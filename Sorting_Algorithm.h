#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
#include <iostream>

//Tuong tu typedef struct 
using List = std::vector<int>;

struct Sorting {
	
	void Selection_sort(int* arr, int n);

	void Insertion_sort(int* arr, int n);

	void Bubble_sort(int* arr, int n);

	void Shaker_sort(int* arr, int n);

	void Shell_sort(int* arr, int n);

	void heapRebuild(int start, int* arr, int n);
	void Heap_sort(int* arr, int n);

	void merge(int* arr, int first, int mid, int last);
	void Merge_sort(int* arr, int first, int last);

	void Quick_sort(int* arr, int first, int last);

	void Counting_sort(int* arr,int n, int u);

	void Radix_sort(int* arr, int n);
	
	void Flash_sort(int* arr, int n);

};

