#include <iostream>

template <typename T>
T sum(T mas[], int N) {
    float sum = 0;
    for (int i = 0; i<N;i++) {
        sum += mas[i];
    }
    return sum;
}

template <typename T>
T prod(T mas[], int N) {
    T prod = 1;
    for (int i = 0; i<N;i++) {
        prod *= mas[i];
    }
    return prod;
}

template <typename T>
T sqr(T mas[], int N) {
    T sqr = 1;
    for (int i = 0; i<N;i++) {
        sqr *= mas[i] * mas[i];
    }

    return sqr;
}

int main() {
    float mas1[] = { 70.4, 9.1, 2, 3.0003, 4.7, 5 };
    int count1 = 6;
    int mas2[] = { 0,1,2 };
    int count2 = 3;
    double mas3[] = { 0.08, 7.8, 2.98, 3.76, 4.87, 5, 0.1, 0.0008 };
    int count3 = 8;

    std::cout << "Results for float:" << std::endl;
    std::cout << "Sum: " << sum<float>(mas1,count1) << std::endl;
    std::cout << "Prod: " << prod<float>(mas1,count1) << std::endl;
    std::cout << "Sqr: " << sqr<float>(mas1,count1) << std::endl;

    std::cout << "Results for int:" << std::endl;
    std::cout << "Sum: " << sum<int>(mas2,count2) << std::endl;
    std::cout << "Prod: " << prod<int>(mas2,count2) << std::endl;
    std::cout << "Sqr: " << sqr<int>(mas2,count2) << std::endl;

    std::cout << "Results for double:" << std::endl;
    std::cout << "Sum: " << sum<double>(mas3,count3) << std::endl;
    std::cout << "Prod: " << prod<double>(mas3,count3) << std::endl;
    std::cout << "Sqr: " << sqr<double>(mas3,count3) << std::endl;
    return 0;
}
