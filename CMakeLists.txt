cmake_minimum_required(VERSION 3.17)
project(AlgorithmsLabTemplate)

set(CMAKE_CXX_STANDARD 14)

set(ALGORITHMS Algorithms/IAlgorithm.h Algorithms/SqrAlgorithm.h Algorithms/SumAlgorithm.h Algorithms/BubbleSort.h)
set(GENERATORS Generators/IGenerator.h Generators/RandomRealGenerator.h Generators/RandomIntGenerator.h Generators/ConstantGenerator.h Generators/ReverseGenerator.h Generators/EqualRealGenerator.h)
set(OUTPUT Outputs/IOutputListener.h Outputs/ConsoleOutput.cpp Outputs/ConsoleOutput.h Outputs/TXTFileOutput.h Outputs/TXTFileOutput.cpp)
set(LIBS Abstractions.h Algorithm.h Output.h Generator.h)
set(TIMER Timer.h Generator.h)

add_executable(AlgorithmsLabTemplate ${OUTPUT} ${GENERATORS} ${ALGORITHMS} ${LIBS} ${TIMER} main.cpp Examples.cpp)