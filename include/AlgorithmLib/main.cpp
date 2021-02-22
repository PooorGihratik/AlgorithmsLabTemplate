#include "StackLib.h"

int main() {
    Stack<float> stack;
    stack.print();
    stack.push(5);
    stack.push(20);
    stack.push(19);
    stack.push(7);
    stack.push(19);
    stack.push(7);
    stack.print();
    stack.pop();
    stack.pop();
    stack.push(700);
    stack.push(190);
    stack.push(630);
    stack.print();
    std::cout << stack.top() << std::endl;
    stack.clear();
    stack.print();
}