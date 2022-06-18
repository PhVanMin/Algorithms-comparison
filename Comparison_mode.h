#pragma once
#include "Sorting_Algorithm.h"
#include "Algorithm_Mode.h"

using List = std::vector<int>;
//comparison mode
struct CM{
    //output parameter in comparison mode: always -both
    void sort_factors(int* arr,int n, int argc, char**argv);
    //– Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
    void Command_4(int argc, char** argv);
    //– Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
    void Command_5(int argc, char** argv);
};
