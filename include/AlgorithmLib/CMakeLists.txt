cmake_minimum_required(VERSION 3.17)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

set(ALGORITHM Algorithms/IAlgorithm.h Algorithms/SqrAlgorithm.h Algorithms/SumAlgorithm.h Algorithms/BubbleSort.h Algorithms/QuickSort.h Algorithms/QuickLibSort.h Algorithms/BinarySearch.h Algorithms/LinearSearch.h)
set(GENERATOR Generators/IGenerator.h Generators/RandomRealGenerator.h Generators/RandomIntGenerator.h Generators/ConstantGenerator.h Generators/ReverseGenerator.h Generators/EqualRealGenerator.h Generators/WorstCaseGenerator.h Generators/SearchGenerator.h)
set(OUTPUT Outputs/IOutputListener.h Outputs/ConsoleOutput.cpp Outputs/ConsoleOutput.h Outputs/TXTFileOutput.h Outputs/TXTFileOutput.cpp)
set(INCLUDEFILES Abstractions.h Algorithm.h Output.h Generator.h VectorLib.h)
set(TIMER Timer.h)
set(VECTORLIB Vector2fLib/Vector2f.cpp Vector2fLib/Vector2f.h Vector2fLib/Vector2fRandGenerator.h Algorithms/BinarySearch.h)

add_library(Algorithms ${OUTPUT} ${GENERATOR} ${ALGORITHM} ${INCLUDEFILES} ${TIMER} ${VECTORLIB})