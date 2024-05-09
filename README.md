# HW3

This is a markdown (md) file representing an 
on-going design for assignment 3 for ECS36C.

## Problem Statement

• Download the hw03.cpp file from Canvas -> Assignments -> Homework03.
• Write your code (in C++) in the designated positions in hw03.cpp
• The purpose of the homework is to practice using some of the concepts gone over in class. The problems
in the first two functions must be solved using stacks. You may use std::stack. If you don’t solve them with
the stack, no points will be given.
• To submit, upload hw03 to Gradescope. Because of the way the autograder on Gradescope is configured,
the file must be named hw03; otherwise, the test cases will not run and you will not get any points.
• Only some of the functions will be for code. It may be different for each student.
• The main portion of your points will come from your explanation. Please make sure to document each line
of code and write a small statement explaining your thought process underneath the function in the
comments.
• You may upload as many times as you want before the deadline. Each time the autograder will let you know
how many of the test cases you have passed/failed. To prevent people from manipulating the autogader,
the content of half of the test cases are hidden.
• Please do not copy others’ answers. Autograder can detect similar code. Also, for your own benefit, do not
try to find solutions online.

## What We Know

We have to implement the following functions:

### `float postfixEval(const std::vector<std::string>& tokens)`

Write a function named postfixEval such that given a postfix expression, evaluate it and return the result. 
Assumptions: 
•  the operands are floats 
•  the possible operators are +, -, *, / 
•  the input expression is always a valid and none-empty postfix expression 
Example: When input is ["2", "4", "7", "∗", "−"], which is 2 − 4 ∗ 7 using infix notation, your function should -26.

2, 4, 7, *, -

Operands:
2, 4, 7

Operators:
*, -

input: 2, 4, 7, *, -
stack: []

input: 4, 7, *, -
stack: [2]

input: 7, *, -
stack: [4, 2]

input: *, -
stack: [7 4 2]

// Take two off of the stack and perform the operation, then push the result back into the stack
pop once: 7
pop twice: 4
operator: *
result: 28

IF stack is not empty
push: 28

input: -
stack: [28 2]

pop: 28
pop: 2
stack: []
operator: -
result: 2 - 28 = -26

stack IS empty: []
do not push to stack, instead return -26

if (currentToken == "*") {

} else if (currentToken == "-") {

} else if (currentToken == "+") {

} else if (currentToken == "/") {

} else {
    
}

switch (currentToken) {
    case "*":
        let firstOperand = stack.pop()
        let secondOperand = stack.pop()
        let result = firstOperand * secondOperand
        if (!stack.empty()) {
            stack.push(result)
        }
    case "-":
        let firstOperand = stack.pop()
        let secondOperand = stack.pop()
        let result = firstOperand - secondOperand
        if (!stack.empty()) {
            stack.push(result)
        }
    case "+":
        let firstOperand = stack.pop()
        let secondOperand = stack.pop()
        let result = firstOperand + secondOperand
        if (!stack.empty()) {
            stack.push(result)
        }
    case "/":
        let firstOperand = stack.pop()
        let secondOperand = stack.pop()
        let result = firstOperand / secondOperand
        if (!stack.empty()) {
            stack.push(result)
        }
    default:
        // read the number probably using atoi and push to stack
}

### `bool validParentheses(const std::string& s)`

Valid examples:

"()"
stack: []
(, stack: [ ( ]
), pop: "("

"abcdef"
stack: []
return true;

"[abc](def)"

input: "[abc](def)"

stack: []
token: "[" -> add to stack

stack: [ "[" ]
token: "a" -> skip

stack: [ "[" ]
token: "b" -> skip

stack: [ "[" ]
token: "c" -> skip

stack: [ "[" ]
token: "]" -> pop, and check if they are compatible
pop: "["
compatible?

stack: []
token: "(" -> push to stack

stack: [ "(" ]
token: "d" -> skip

stack: [ "(" ]
token: "e" -> skip

stack: [ "(" ]
token: "f" -> skip

stack: [ "(" ]
token: ")" -> pop, check for compatibility
pop: "("
compatible? yes

return true;

FILO:
"{([hijk])}"

input: "{([hijk])}"

stack: []
token: "{" -> push to stack

stack: [ "{" ]
token: "(" -> push to stack

stack: ["(" "{"]
token: "[" -> push to stack

stack: ["[" "(" "{"]
token: h -> skip
token: i -> skip
token: j -> skip
token: k -> skip

stack: ["[" "(" "{"]
token: "]" -> pop, check for compatibility
pop: "["
compatible!

stack: ["(" "{"]
token: ")" -> check if stack is empty....if so, return false! pop, check for compatibility
pop: "("
compatible!

stack: ["{"]
token: "}" -> pop, check for compatibility
pop: "{"
compatible!

return true;

Invalid examples:
"{]"

"abcd(ef"

stack: []
a: skip
b: skip
c: skip
d: skip
( -> push to stack
e: skip
f: skip

if (!stack.empty()) return false;

return true;

"[abc}{def)"

input: "[abc}{def)"

stack: []
token: "[" -> push them to stack

stack: [ "[" ]
token: a -> skip

stack: [ "[" ]
token: b -> skip

stack: [ "[" ]
token: c -> skip

stack: [ "[" ]
token: } -> pop, and check for compatibility
pop: "["
compatible? no...return false;

stack: []

loop per character in string, token = str[i]
inside loop:
switch (token) {
    case "[":
        // Push character to stack
    case "{":
        // Push character to stack
    case "(":
        // Push character to stack
    case "]":
        // If stack is empty, return false
        // Pop and check if it is the complement
        // If it is, keep going. If it is not, return false
    case "}":
        // If stack is empty, return false
        // Pop and check if it is the complement
        // If it is, keep going. If it is not, return false
    case ")":
        // If stack is empty, return false
        // Pop and check if it is the complement
        // If it is, keep going. If it is not, return false
    default:
        // do nothing
        break;
}

// After your loop:

if (stack.Empty) {
    return true; // Proccesed everything!
} else {
    return false;
}

### `void Stack2::push(int x)`

a, b, c, d
stack: [ d c b a ]
queue: [ a b c d ]

### `void Stack2::pop()`

### `int Stack2::top()`

### `bool Stack2::empty()`

### `std::list<int> concatenate(const std::list<int>& list1, const std::list<int>& list2)`

### `std::list<int> removeNodesFromBeginning(std::list<int>& list, int n)`

### `std::list<int> removeNodes(std::list<int>& list, int i, int n)`

## `void buildHeap(std::vector<int>& arr)`

## Unanswered Questions

## To-Dos

<ol>
    <li>Add the HW3.cpp file to this project.</li>
    <li></li>
</ol>