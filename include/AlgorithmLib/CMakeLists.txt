cmake_minimum_required(VERSION 3.17)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

set(ALGORITHM Algorithms/IAlgorithm.h Algorithms/SqrAlgorithm.h Algorithms/SumAlgorithm.h Algorithms/BubbleSort.h Algorithms/QuickSort.h Algorithms/QuickLibSort.h Algorithms/BinarySearch.h Algorithms/LinearSearch.h Algorithms/ProdAlgorithm.h)
set(GENERATOR Generators/IGenerator.h Generators/RandomRealGenerator.h Generators/RandomIntGenerator.h Generators/ConstantGenerator.h Generators/ReverseGenerator.h Generators/EqualRealGenerator.h Generators/WorstCaseGenerator.h Generators/SearchGenerator.h)
set(OUTPUT Outputs/IOutputListener.h Outputs/ConsoleOutput.cpp Outputs/ConsoleOutput.h Outputs/TXTFileOutput.h Outputs/TXTFileOutput.cpp)
set(INCLUDE_FILES Abstractions.h Algorithm.h Output.h Generator.h VectorLib.h StackLib.h)
set(TIMER Timer.h)
set(VECTOR_LIB Vector2fLib/Vector2f.cpp Vector2fLib/Vector2f.h Vector2fLib/Vector2fRandGenerator.h Algorithms/BinarySearch.h)
set(STACK_STRUCTURE StackStructure/Stack.h StackStructure/DeleteAlgorithm.h StackStructure/AddAlgorithm.h)

add_library(Algorithms ${OUTPUT} ${GENERATOR} ${ALGORITHM} ${INCLUDE_FILES} ${TIMER} ${VECTOR_LIB} ${STACK_STRUCTURE} main.cpp)
add_executable(Test ${OUTPUT} ${GENERATOR} ${ALGORITHM} ${INCLUDE_FILES} ${TIMER} ${VECTOR_LIB} ${STACK_STRUCTURE} main.cpp main.cpp)