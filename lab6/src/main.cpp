#include <vector>
#include <AlgorithmLib/VectorLib.h>
#include <algorithm>

template<typename T>
void sqrAllVal(std::vector<T>& array) {
    std::for_each(array.begin(), array.end(), [](T &val) { val *= val; });
}

template<typename T>
auto findValue(std::vector<T>& array) {
    T valPrev = array[0];
    bool bufferVal = false;
    auto iter = std::find_if(array.begin()+1,array.end(),[&valPrev, &bufferVal](T val) {
        bool result = val > valPrev;
        bool currentState = bufferVal;
        if (bufferVal) result = val < valPrev;
        bufferVal = result;
        return currentState && result;
    } );
    return iter != array.end() ? iter-1 : array.end();
}

template<typename T>
void sortByDecreasing(std::vector<T>& array) {
    std::sort(array.begin(),array.end(),std::greater<T>());
}

template<typename T>
void deleteMaxElement(std::vector<T>& array) {
    auto iter = std::max_element(array.begin(),array.end());
    std::cout << "\nMax element: " << *iter << "\n";
    array.erase(iter);
}


template<typename T>
void swapValues(std::vector<T>& array, int N) {
    for ( int i = 0; i<N; i++) {
        auto iter1 = array.begin() + i;
        auto iter2 = array.end() - i - 1;
        std::iter_swap(iter1,iter2);
    }
}

template<typename T>
void printArray(const std::vector<T>& array) {
    std::cout << "\nCurrent array:\n";
    for (const auto &item : array) {
        std::cout << item << "\n";
    }
}

int main() {
    int count = 20;
    RandomRealGenerator<float> ran;
    Vector2fRandGenerator gen;
    Vector2f* vec = gen.getValues(count);
    std::vector<Vector2f> array(vec, vec+count);
    printArray(array);

    swapValues(array, 3);
    printArray(array);

    deleteMaxElement(array);
    printArray(array);

    //sortByDecreasing(array);
    auto iter = findValue(array);
    if (iter != array.end()) std::cout << "\nFound value: " << *iter << "\n";
    else std::cout << "\nValue does not exist\n";

    sortByDecreasing(array);
    printArray(array);

    float* fl = ran.getValues(count);
    std::vector<float> arr(fl, fl+count);
    printArray(arr);
    sqrAllVal(arr);
    printArray(arr);
}
