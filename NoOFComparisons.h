#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>

#define MAX_SIZE 1000000
using List = std::vector<int>;

struct NoOFCompare {
	void Selection_sort(int* arr,int n, unsigned long long &count_compare);

	void Insertion_sort(int* arr,int n, unsigned long long &count_compare);

	void Bubble_sort(int* arr,int n, unsigned long long &count_compare);

	void Shaker_sort(int* arr, int n,unsigned long long &count_compare);

	void Shell_sort(int* arr,int n, unsigned long long &count_compare);

	void heapRebuild(int start, int* arr, int n, unsigned long long &count_compare);
	void Heap_sort(int* arr,int n, unsigned long long &count_compare);

	void merge(int* arr, int first, int mid, int last, unsigned long long &count_compare);
	void Merge_sort(int* arr, int first, int last, unsigned long long &count_compare);

	void Quick_sort(int* arr, int first, int last, unsigned long long& count_compare);

	void Counting_sort(int* arr,int n, int u, unsigned long long &count_compare);

	void Radix_sort(int* arr,int n, unsigned long long &count_compare);
	
	void Flash_sort(int* arr,int n, unsigned long long &count_compare);

	// mot so ham chua co du tham so nen mn lam ham nao thi sua ham do
};