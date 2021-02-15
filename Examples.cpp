//
// Created by Кир on 15.02.2021.
//
#include <iostream>
#include "Timer.h"

#include "Output.h"
#include "Generator.h"
#include "Algorithm.h"

// This is an example of using different generators

void exampleAlg() {

    // Generators init
    // Here can be used only Real number types (float, double, etc)
    RandomRealGenerator<float> real;

    // Here can be used only Integer number types (int, byte, etc)
    RandomIntGenerator<int> integ;

    // Here you can use any number type ( it just fill the array with 1 )
    ConstantGenerator<float> con1;
    ConstantGenerator<int> con2;

    // Algoritms Init
    // When initialising the algorithms, be sure that the types of generator is equal
    alg::BubbleSort<float> bubbleF;
    alg::BubbleSort<int> bubbleI;

    // Setting the algorithms to show the results in console
    // (this methods does not declared in IAlgorithm interface)
    bubbleF.setShowState(true);
    bubbleI.setShowState(true);

    // Generating the random numbers and sort them
    bubbleF.execute(real.getValues(10),10);
    bubbleI.execute(integ.getValues(10),10);

    // Fill array with 1 and try to sort them
    bubbleF.execute(con1.getValues(10),10);
    bubbleI.execute(con2.getValues(10),10);

};

// This is example of using the Timer

void exampleTimer() {

    // Generators and algorithms init
    // Note:
    // All generators have to implement IGenerator interface
    // All algorithms have to implement IAlgorithm interface
    RandomRealGenerator<float> real;
    alg::BubbleSort<float> bubbleF;
    alg::SumAlgorithm<float> sum;

    // Timer init
    // As the last param you should pass the name of output
    // (name of file, console output, etc)
    Timer<float> timer(&real, &bubbleF, "float");

    // Adding the console OutputListeners for printing set of auto-measure results
    // Note:
    // All OutputListeners have to implement IGenerator interface
    ConsoleOutput console;
    timer.addOutputListener(&console);

    // There is 2 different options for measure results
    // 1. Auto measure
    // Timer automatically measure the time with set of sizes of array
    // (Size is 1000,2000,5000,10000,...,500000)
    // Results will be printed in all added outputs
    timer.measureAndPrint();

    // 2. Manual measure
    // Timer measure the time with given size of array
    // And return the time
    float time = timer.measure(100);
    std::cout << "Measured time: " << time << std::endl;

}