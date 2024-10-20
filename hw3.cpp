
#include "hw3.h"
#include <stack>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main() {
   /*
       // Test for remove_duplicates function
    std::list<int> linked_list = {1, 2, 2, 3, 4, 4, 4, 5};
    remove_duplicates(linked_list);
    std::cout << "Linked list after removing duplicates: ";
    for (int num : linked_list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    

    // Test for postfixEval function
    std::vector<std::string> postfix_expr = {"2", "4", "7", "*", "+"};
    float eval_result = postfixEval(postfix_expr);
    std::cout << "Result of postfix evaluation: " << eval_result << std::endl;

    //Test for validParentheses function
    std::string parentheses = "(ab){[()]}";
    bool valid = validParentheses(parentheses);
    std::cout << "Parentheses are " << (valid ? "valid" : "invalid") << std::endl;

    // Tests for additional functions can be added here following similar patterns
*/
    return 0;
}


float postfixEval(const std::vector<std::string>& tokens) {
    // TODO: Student to implement

    return 0.0f; // Placeholder return

    std::stack<float> stack;

    for (const std::string& token : tokens) {
     /*This loop iterates through each token in the tokens collection. 
     Each token represents either an operator (+, -, *, /) or an operand (a number)*/

        if (token == "+" || token == "-" || token == "*" || token == "/") {
        /*this checks if the current token is an operator*/

            float operand2 = stack.top();
            stack.pop();
            float operand1 = stack.top();
            stack.pop();
            float result;
            /*These lines retrieve the top two operands from the stack*/

            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {  
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "/") {
                result = operand1 / operand2;
            }
            /*These lines evaluate the result of applying the operator to the two operands*/

            stack.push(result);
            /*result is pushed back onto the stack for more evaluation*/
        } else {
            float operand = std::stof(token);
            stack.push(operand);
            /*If the token is not an operator it converts the token to a float and pushes it onto the stack*/
        }
    }
    return stack.top();
    // final result is at top of the stack
} 
/* My thought process behind the code was that When it encounters an operator, it pulls out the last two numbers, 
does the math, and puts the result back in the stack. It returns the last number left in the stack, 
which is the result of the expression.*/


bool validParentheses(const std::string& s) {
    std::stack<char> stack; // Create a stack to store opening parentheses

// Loops through each character in the string
    for (char c : s) {

        // If the character is an opening parenthesis it is pushed onto the stack
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
            
        } else if (c == ')' || c == '}' || c == ']') // If the character is a closing parenthesis
        {
            // If the stack is empty there is no corresponding opening parenthesis so return false
            if (stack.empty()) {
                return false;
            }
            // Get the top element from the stack
            char top = stack.top();
            // Remove the top element from the stack
            stack.pop();

            // Check if the current closing parenthesis matches the top of the stack
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false; //If they dont match return false
            }
        }
    }

    return stack.empty(); // If the stack is empty then all parentheses match
}
/*the code uses a stack to keep track of opening parentheses encountered in a string, checking if each closing 
parenthesis matches the most recent opening one. If the stack is empty at the end, it means all parentheses are 
properly balanced*/

void Stack2::push(int x) {
    // TODO: Student to implement
}

void Stack2::pop() {
    // TODO: Student to implement


}

int Stack2::top() {
    // TODO: Student to implement
    return 0; // Placeholder return
}

bool Stack2::empty() {
    // TODO: Student to implement
    return true; // Placeholder return
}

std::list<int> concatenate(const std::list<int>& list1, const std::list<int>& list2) {

    // Create a new list 'result' and initialize it with elements from list1
    std::list<int> result = list1;
    // Insert elements from list2 at the end of 'result'
    result.insert(result.end(), list2.begin(), list2.end());

    return result;
}


std::list<int> removeNodesFromBeginning(std::list<int>& list, int n) {
    // TODO: Student to implement

    // Loop to remove the first n nodes from the list
    for (int i = 0; i < n; i++) {
        // Check if the list is not empty before removing a node
        if (!list.empty()) {
            list.pop_front(); // Remove the first node from the list
        }
    }
    return list;
}


std::list<int> removeNodes(std::list<int>& list, int i, int n) {
    // TODO: Student to implement
    // Get an iterator pointing to the 'i'th position in the list
    std::list<int>::iterator it = list.begin();
    std::advance(it, i - 1); // Move the iterator i - 1 positions forward

    // Get an iterator pointing to the node after the last node to be removed
    std::list<int>::iterator end = it;
    std::advance(end, n + 1); // Move the end iterator n + 1 positions forward

    // Erase nodes from it + 1 to end 
    list.erase(std::next(it), end);

    return list; // Return the modified list
}

/* The code aims to remove a specified number of nodes from a list, starting from a given position. 
It does this by  advancing an iterator to the desired starting position then erasing a range of nodes from 
that position up to the specified count.*/

void buildHeap(std::vector<int>& arr) {
    // TODO: Student to implement
int n = arr.size(); // Get the size of the vector

// Build max heap
for (int i = n / 2 - 1; i >= 0; i--) {
    int parent = i;
    int child = 2 * parent + 1;

    // Perform heapify operation
    while (child < n) {
        // Check if the right child exists and is greater than the left child
        if (child + 1 < n && arr[child + 1] > arr[child]) {
            child++;
        }

        // Swap if the child is greater than the parent
        if (arr[child] > arr[parent]) {
            std::swap(arr[child], arr[parent]);
            parent = child;
            child = 2 * parent + 1;
        } else {
            break; // If the parent is greater, break the loop
        }
    }
}

// Heap sort
for (int i = n - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);  // Move the largest element to the end

    int parent = 0;
    int child = 2 * parent + 1;

    // Perform heapify operation after removing the largest element
    while (child < i) {
        // Check if the right child exists and is greater than the left child
        if (child + 1 < i && arr[child + 1] > arr[child]) {
            child++;
        }
        // Swap if the child is greater than the parent
        if (arr[child] > arr[parent]) {
            std::swap(arr[child], arr[parent]);
            parent = child;
            child = 2 * parent + 1;
        } else {
            break; // If the parent is greater then break the loop
        }
    }
}

//return arr;

}
/* The code to constructs a max heap from a given vector of integers and then performs heap sort to 
arrange the elements in ascending order. It iterates through the vector to build the heap structure and then
applies heap sort to rearrange the elements. The largest element is placed at the end in each 
iteration.*/
