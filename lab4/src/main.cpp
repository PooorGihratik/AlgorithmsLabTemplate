#include <iostream>
#include <AlgorithmLib/Algorithm.h>
#include <AlgorithmLib/Generator.h>
#include <AlgorithmLib/Timer.h>
#include <AlgorithmLib/Output.h>
#include <AlgorithmLib/VectorLib.h>

void TaskB2() {
    float item = 50;
    RandomRealGenerator<float> gen;

    LinearSearch<float> linear;
    linear.setSearchItem(item);

    SearchGenerator<float> searchGen(&gen);
    searchGen.setSearchItem(item);

    int count = 10;
    float* array = searchGen.getValues(count);
    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nIndex of found item (" << item << "): " << linear.findItem(array, count, item) << "\n";

    count = 15;
    array = searchGen.getValues(count);
    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nIndex of found item (" << item << "): " << linear.findItem(array, count, item) << "\n";

    count = 20;
    array = searchGen.getValues(count);
    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nIndex of found item (" << item << "): " << linear.findItem(array, count, item) << "\n";
}

void TaskA2() {
    float item = 50;
    QuickSort<float> quick;
    RandomRealGenerator<float> gen;

    BinarySearch<float> bin;
    bin.setSearchItem(item);

    SearchGenerator<float> searchGen(&gen);
    searchGen.setSortAlgorithm(&quick);
    searchGen.setSearchItem(item);

    int count = 10;
    float* array = searchGen.getValues(count);
    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nIndex of found item (" << item << "): " << bin.findItem(array,count,item) << "\n";
    delete[] array;

    count = 15;
    array = searchGen.getValues(count);
    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nIndex of found item (" << item << "): " << bin.findItem(array,count,item) << "\n";
    delete[] array;

    count = 20;
    array = searchGen.getValues(count);
    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nIndex of found item (" << item << "): " << bin.findItem(array,count,item) << "\n";
    delete[] array;
}

void Task3() {
    Vector2f item(3,5);
    Vector2fRandGenerator generator;
    QuickSort<Vector2f> quick;

    LinearSearch<Vector2f> lin;
    BinarySearch<Vector2f> bin;
    SearchGenerator<Vector2f> searchGen(&generator);
    searchGen.setSearchItem(item);
    searchGen.setSortAlgorithm(&quick);

    int count = 10;
    Vector2f* array = searchGen.getValues(count);
    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nIndex of found item (" << item << "): " << bin.findItem(array,count,item) << "\n";
    delete[] array;

    array = searchGen.getValues(count);
    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nIndex of found item (" << item << "): " << lin.findItem(array,count,item) << "\n";
    delete[] array;
}

void Task4() {
    float item = 50;
    EqualRealGenerator<float> gen;
    QuickSort<float> quick;

    BinarySearch<float> binary;
    LinearSearch<float> linear;
    linear.setSearchItem(item);
    binary.setSearchItem(item);

    SearchGenerator<float> searchGen(&gen);
    searchGen.setSearchItem(item);
    searchGen.setSortAlgorithm(&quick);

    Timer<float> timer(&searchGen,&binary,"Binary");
    std::vector<int> measureSet;
    for (int i = 1; i <= 50; i++) {
        measureSet.push_back(10000*i);
    }
    timer.setMeasureSet(measureSet);
    timer.addOutputListener(new TXTFileOutput);
    timer.addOutputListener(new ConsoleOutput);
    timer.autoMeasureWithSet();

    timer.setName("Linear");
    timer.setAlgorithm(&linear);
    timer.autoMeasureWithSet();
}

int main() {
    Task4();
    return 0;
}
