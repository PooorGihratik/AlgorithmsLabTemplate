#include <AlgorithmLib/Algorithm.h>
#include <AlgorithmLib/Generator.h>
#include <AlgorithmLib/Timer.h>
#include <AlgorithmLib/Output.h>

int main() {
    RandomRealGenerator<float> gen;
    ConstantGenerator<float> con;
    ConsoleOutput console;
    TXTFileOutput file;

    SumAlgorithm<float> sum;
    Timer<float> timer(&gen, &sum, "float");
    timer.addOutputListener(&console);
    timer.autoMeasureWithSet();

    ProdAlgorithm<float> prod;
    timer.setAlgorithm(&prod);
    timer.autoMeasureWithSet();

    SqrAlgorithm<float> sqr;
    timer.setAlgorithm(&sqr);
    timer.autoMeasureWithSet();

    timer.setGenerator(&con);
    timer.autoMeasureWithSet();

    timer.setAlgorithm(&sum);
    timer.autoMeasureWithSet();

    timer.setGenerator(&con);
    timer.addOutputListener(&file);
    timer.setAlgorithm(&sqr);
    timer.autoMeasureWithSet();

    RandomRealGenerator<double> gen1;
    SqrAlgorithm<double> sqr1;
    Timer<double> timer1(&gen1, &sqr1, "double");
    timer1.addOutputListener(&file);
    timer1.autoMeasureWithSet();

    RandomIntGenerator<int> gen2;
    SqrAlgorithm<int> sqr2;
    Timer<int> timer2(&gen2, &sqr2, "int");
    timer2.addOutputListener(&file);
    timer2.autoMeasureWithSet();

    return 0;
}
