#include <iostream>
#include <AlgorithmLib/Algorithm.h>
#include <AlgorithmLib/Generator.h>
#include <AlgorithmLib/Timer.h>
#include <AlgorithmLib/VectorLib.h>
#include <AlgorithmLib/Output.h>

void Task2() {
    float item = 50;
    QuickSort<float> quick;
    RandomRealGenerator<float> gen;

    BinarySearch<float> bin;
    bin.setSearchItem(item);

    SearchGenerator<float> search(&gen);
    search.setSortAlgorithm(&quick);
    search.setSearchItem(item);

    int count = 10;
    float* array = search.getValues(count);

    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\nIndex of found item (" << item << "): " << bin.findItem(array,count,item) << "\n";

    count = 15;
    array = search.getValues(count);

    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\nIndex of found item (" << item << "): " << bin.findItem(array,count,item) << "\n";

    count = 20;
    array = search.getValues(count);

    std::cout << "Array: \n";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\nIndex of found item (" << item << "): " << bin.findItem(array,count,item) << "\n";
}

void Task3() {

}

int main() {
    Task2();

    return 0;
}
