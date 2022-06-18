#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include "Sorting_Algorithm.h"
#include "NoOFComparisons.h"

using List = std::vector<int>;


struct AM{
    //Copy array
    int* copyArray(int* arr, int n);

    //Get position form sort_method
    int get_algorithm(std::string sort_method);

    //Execute suitable function based on sort method which is cmdline argument
    void execute_Sorting(int*  arr, int n, std::string sort_method, int pos);

    //Based on sorting algorithm to calculate time of executing function
	int Running_time(int*  arr,int n, std::string sort_method);

    //Execute suitable function based on sort method which is cmdline argument
    void execute_Sorting_Comparison(int*  arr, int n, std::string sort_method,int pos, unsigned long long& count_compare);
    //Based on sorting algorithm to calculate the number of comparisons of executing function
	unsigned long long Number_Of_Comparisons(int*  arr,int n, std::string sort_method);
    
    //Input arguments
    void Mode(int argc, char** argv);
    void Algorithm_name(int argc, char** argv);
    int Input_size(int argc, char** argv);
    //Types of data
    int* Input_order(int& n, int argc, char** argv);
    //Get the data from the input file (txt file)
    int* Given_Input_File(int& n, int argc, char** argv);
    //Time or comparisons or both
    void Output_parameter(int* arr,int n, std::string s, int argc, char** argv);

    //Writing file for cmd 1 2 3 5 - sorted array or generate input
    void Write_file_1(int*  arr,int n, std::string FileName);

    //– Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
    void Command_1(int argc, char** argv);
    //– Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
    void Command_2(int argc, char** argv);
    //– Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
    void Command_3(int argc, char** argv);
};
