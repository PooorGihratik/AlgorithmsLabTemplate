#include <iostream>
#include <AlgorithmLib/Algorithm.h>
#include <AlgorithmLib/Generator.h>
#include <AlgorithmLib/Timer.h>
#include <AlgorithmLib/Output.h>
#include <AlgorithmLib/VectorLib.h>

void Task12() {
    RandomRealGenerator<float> ran1;
    ConsoleOutput console;
    BubbleSort<float> bubble;
    QuickSort<float> quick;
    Timer<float> timer(&ran1, &bubble, "float");

    // Task 1
    std::cout << "=========================\n";
    std::cout << "Task 1: \n";
    int c1 = 10;
    int c2 = 100;
    int c3 = 200;
    bubble.execute(ran1.getValues(c1), c1);
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Array sorted: " << bubble.isSorted() << "\n";
    bubble.execute(ran1.getValues(c2),c2);
    std::cout << "Array sorted: " << bubble.isSorted() << "\n";
    bubble.execute(ran1.getValues(c3),c3);
    std::cout << "Array sorted: " << bubble.isSorted() << "\n";
    std::cout << "=========================\n\n";

    // Task 2
    std::cout << "===========================\n";
    std::cout << "Task 2: \n";
    bubble.setShowState(true);
    bubble.setShowIndex(true);
    quick.setShowState(true);
    quick.setShowIndex(true);
    float time = timer.measure(10);
    std::cout << "Work time: " << time << " ms\n" << std::endl;
    timer.setAlgorithm(&quick);
    time = timer.measure(10);
    std::cout << "Work time: " << time << " ms" << std::endl;
    std::cout << "Array sorted: " << quick.isSorted() << "\n";
    std::cout << "============================\n\n";
}

void Task3() {
    std::cout << "=========================\n";
    std::cout << "Task 3: \n";
    int c1 = 10;
    int c2 = 100;
    int c3 = 200;
    QuickSort<Vector2f> quick;
    Vector2fRandGenerator vec;
    Vector2f* vecA =  vec.getValues(c1);
    quick.execute(vecA, c1);
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Array sorted: " << quick.isSorted() << "\n";
    quick.execute(vec.getValues(c2),c2);
    std::cout << "Array sorted: " << quick.isSorted() << "\n";
    quick.execute(vec.getValues(c3),c3);
    std::cout << "Array sorted: " << quick.isSorted() << "\n";
    std::cout << "Array example: ";
    for (int i = 0; i < c1; ++i) {
        std::cout << vecA[i] << " ";
    }
    std::cout << "\n";
    std::cout << "=========================\n\n";
}

void Task4() {
    std::cout << "=========================\n";
    std::cout << "Task 4: \n";
    RandomRealGenerator<float> gen;
    TXTFileOutput file;
    BubbleSort<float> bubble;
    QuickSort<float> quick;
    Timer<float> timer1(&gen, &bubble, "bubbleSort");
    Timer<float> timer2(&gen, &quick, "quickSort");
    timer2.addOutputListener(&file);
    timer1.addOutputListener(&file);
    std::vector<int> measureSet;
    for (int i = 1; i <= 50; i++) {
        measureSet.push_back(1000*i);
    }
    timer1.setMeasureSet(measureSet);
    timer2.setMeasureSet(measureSet);
    timer1.autoMeasureWithSet();
    timer2.autoMeasureWithSet();
    std::cout << "Array has been sorted and time is measured\n";
    std::cout << "=========================\n\n";
}

void Task5() {
    std::cout << "=========================\n";
    std::cout << "Task 5: \n";
    ConstantGenerator<float> gen1;
    ReverseGenerator<float> gen;
    TXTFileOutput file;
    QuickSort<float> quick;
    Timer<float> timer1(&gen, &quick, "quickReverseSort");
    Timer<float> timer2(&gen1, &quick, "quickConstSort");
    timer2.addOutputListener(&file);
    timer1.addOutputListener(&file);
    std::vector<int> measureSet;
    for (int i = 1; i <= 50; i++) {
        measureSet.push_back(1000*i);
    }
    timer1.setMeasureSet(measureSet);
    timer2.setMeasureSet(measureSet);
    timer1.autoMeasureWithSet();
    timer2.autoMeasureWithSet();
    std::cout << "Array has been sorted and time is measured\n";
    std::cout << "=========================\n\n";
}

void AdditionalTask() {
    // Additional task: Compare std::sort and hand realisation
    WorstCaseGenerator<float> gen;
    QuickSort<float> quick1;
    QuickLibSort<float> quick2;
    ConsoleOutput cons;
    TXTFileOutput txt;
    Timer<float> timer(&gen, &quick2, "Lib");
    std::vector<int> measureSet;
    for (int i = 1; i <= 50; i++) {
        measureSet.push_back(1000*i);
    }
    timer.setMeasureSet(measureSet);
    timer.addOutputListener(&cons);
    timer.addOutputListener(&txt);
    timer.autoMeasureWithSet();

    timer.setName("Hand");
    timer.setAlgorithm(&quick1);
    timer.autoMeasureWithSet();
}

int main() {
    /*Task12();
    Task3();
    Task4();
    Task5();*/
    AdditionalTask();
    return 0;
}
