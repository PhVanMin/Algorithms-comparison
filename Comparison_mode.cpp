#include "Comparison_mode.h"

void CM::sort_factors(int* arr,int n, int argc, char** argv){
    AM* am = nullptr;
    //Initialize virtual array
    double time_1, time_2;
    //Calculate time of first sort
    int* A = am->copyArray(arr,n);
    time_1 = am->Running_time(A,n,argv[2]);
    delete[]A;
    //Calculate time of second sort
    int* B = am->copyArray(arr,n);
    time_2 = am->Running_time(B,n,argv[3]);
    delete[]B;
    unsigned long long comp_1, comp_2;
    //Calculate the number of comparisons of first sort
    int* C = am->copyArray(arr,n);
    comp_1= am->Number_Of_Comparisons(C,n,argv[2]);
    delete[]C;
    //Calculate the number of comparisons of second sort
    int* D = am->copyArray(arr,n);
    comp_2 = am->Number_Of_Comparisons(D,n,argv[3]);
    delete[]D;
    //Display running time and the number of comparisons in both sorting algorithm
    std::cout <<"Running time: " << time_1 << " | " << time_2 << std::endl;
    std::cout<<"Comparisons: "<<comp_1<<" | "<<comp_2<<std::endl;
}
void CM::Command_4(int argc, char** argv){
    AM* am = nullptr;
    int n;
    
    am->Mode(argc,argv);
    am->Algorithm_name(argc,argv);
    //Initialize array
    int* arr = am->Given_Input_File(n,argc,argv);

    std::cout<<"---------------------------"<<std::endl;
    sort_factors(arr,n,argc,argv);
    delete[]arr;
}

void CM::Command_5(int argc, char** argv){
    AM* am = nullptr;
    
    am->Mode(argc,argv);
    am->Algorithm_name(argc,argv);
    int n = am->Input_size(argc,argv);
    std::cout<<"Input size: "<< n <<std::endl;
    //Initialize array
    int* arr = am->Input_order(n,argc,argv);
    am->Write_file_1(arr,n,"_input.txt");

    std::cout<<"---------------------------"<<std::endl;
    sort_factors(arr,n,argc,argv);
    delete[]arr;
}
