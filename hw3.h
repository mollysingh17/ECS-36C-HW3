//
// Created by Aneis on 4/30/2024.
//

#ifndef HW3_H
#define HW3_H

#include <vector>
#include <string>
#include <queue>
#include <list>

float postfixEval(const std::vector<std::string>& tokens);
bool validParentheses(const std::string& s);

class Stack2 {
public:
    void push(int x);
    void pop();
    int top();
    bool empty();
private:
    std::queue<int> queue1, queue2;
};

std::list<int> concatenate(const std::list<int>& list1, const std::list<int>& list2);
std::list<int> removeNodesFromBeginning(std::list<int>& list, int n);
std::list<int> removeNodes(std::list<int>& list, int i, int n);
void buildHeap(std::vector<int>& arr);

#endif //HW3_H
