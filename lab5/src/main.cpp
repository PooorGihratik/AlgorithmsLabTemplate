#include <iostream>
#include <AlgorithmLib/Algorithm.h>
#include <AlgorithmLib/Generator.h>
#include <AlgorithmLib/Timer.h>
#include <AlgorithmLib/Output.h>
#include <AlgorithmLib/StackLib.h>

void StackCheck() {
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

void TimeMeasure() {
    EqualRealGenerator<float> gen;
    Stack<float> stack;
    AddAlgorithm<float> add(&stack);
    DeleteAlgorithm<float> del(&stack,&gen);
    ConsoleOutput con;
    TXTFileOutput file;

    Timer<float> timer(&gen,&del,"DeletingHand");
    timer.addOutputListener(&con);
    timer.addOutputListener(&file);

    std::vector<int> measureSet;
    for (int i = 1; i <= 50; i++) {
        measureSet.push_back(1000*i);
    }
    timer.setMeasureSet(measureSet);
    timer.autoMeasureWithSet();

    timer.setAlgorithm(&add);
    timer.setName("AddingHand");
    timer.autoMeasureWithSet();
}

int main() {
    StackCheck();
    TimeMeasure();
}


