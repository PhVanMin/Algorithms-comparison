#include "NoOFComparisons.h"

void NoOFCompare::Selection_sort(int* arr, int n, unsigned long long &count_compare){
	for (int i = 0; ++count_compare && i < n - 1; ++i) {
		// At this point, arr[0..i-1] is sorted, and its
		// entries are smaller than those in arr[i..n-1].
		int minIdx = i; 
		// Select the smallest entry in arr[i..n-1]
		for (int j = i + 1; ++count_compare && j < n; ++j)
			if (++count_compare && arr[j] < arr[minIdx]){
				minIdx = j; 
            }
		// Swap the smallest entry, arr[minIdx], with arr[i]
		std::swap(arr[minIdx], arr[i]); 
	}
}

void NoOFCompare::Insertion_sort(int* arr,int n, unsigned long long &count_compare){
	for (int i = 1; ++count_compare && i < n; ++i){
	// Find the right position in the sorted region arr[0..i-1]
	// for arr[i]; shift, if necessary, to make room
		int key = arr[i];
		int j = i-1;
		while (++count_compare && j >= 0 && ++count_compare && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
	arr[j + 1] = key;
	}
}

void NoOFCompare::Bubble_sort(int* arr, int n,unsigned long long &count_compare){
	for (int i = 0; ++count_compare && i < n - 1; i++)
		for (int j = n - 1; ++count_compare && j > i; j--)
			if (++count_compare && arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
}

void NoOFCompare::Shaker_sort(int* arr,int n, unsigned long long &count_compare){
	int i, j, k;
   	for(i = 0; ++count_compare && i < n;) {
      	for(j = i+1;++count_compare &&  j < n; j++) {
         	if(++count_compare && arr[j] < arr[j-1])
            	std::swap(arr[j], arr[j-1]);
      	}	
      	n--;
      	for(k = n-1; ++count_compare && k > i; k--) {
         	if(++count_compare && arr[k] < arr[k-1])
            	std::swap(arr[k], arr[k-1]);
      	}
      	i++;
   	}
}

void NoOFCompare::Shell_sort(int* arr,int n, unsigned long long &count_compare){
	for (int gap = n/2; ++count_compare && gap > 0; gap /= 2)
    {
        for (int i = gap; ++count_compare && i < n; i += 1)
        {
            int temp = arr[i];
            int j = i;           
            while ((++count_compare && j >= gap) && (++count_compare && arr[j - gap] > temp)) {
                arr[j] = arr[j - gap];
				j-= gap;
			}
            arr[j] = temp;
        }
    }
}


void NoOFCompare::heapRebuild(int start, int* arr, int n, unsigned long long &count_compare){
	int leftChild = 2 * start + 1; // A left child must exist
	if (++count_compare && leftChild >= n) return;
	int largerChild = leftChild; // Make assumption about larger child
	int rightChild = 2 * start + 2; // A right child might not exist
	if (++count_compare && rightChild < n) { // Whether a right child exists
	// A right child exists; check whether it is larger
		if (++count_compare && arr[rightChild] > arr[largerChild])
			largerChild = rightChild; // Assumption was wrong

	}
	// If arr[start] is smaller than the larger child, swap values
	if (++count_compare && arr[start] < arr[largerChild]) {
		std::swap(arr[largerChild], arr[start]);
		heapRebuild(largerChild, arr, n, count_compare); // Recursion at that child
	}
}
void NoOFCompare::Heap_sort(int* arr, int n,unsigned long long &count_compare){
	
	// Build initial heap
	for (int index = (n - 1) / 2; ++count_compare && index >= 0; index--) 
		heapRebuild(index, arr, n, count_compare);
	
	std::swap(arr[0], arr[n - 1]); // swap the largest element to the end
	int heapSize = n - 1; // Heap region size decreases by 1
	while (++count_compare && heapSize > 1) {
		heapRebuild(0, arr, heapSize, count_compare);
		heapSize--;
		std::swap(arr[0], arr[heapSize]);
	}
}

void NoOFCompare::merge(int* arr, int first, int mid, int last, unsigned long long &count_compare){
	int subArrayOne = mid - first + 1;
    int subArrayTwo = last - mid;
 
    // Create temp arrays
    int *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; ++count_compare && i < subArrayOne; i++)
        leftArray[i] = arr[first + i];
    for (int j = 0; ++count_compare && j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = first; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (++count_compare && indexOfSubArrayOne < subArrayOne && ++count_compare && indexOfSubArrayTwo < subArrayTwo) {
        if (++count_compare && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (++count_compare && indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (++count_compare && indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void NoOFCompare::Merge_sort(int* arr, int first, int last, unsigned long long &count_compare){
	if (++count_compare && first < last) {
		int mid = (first + last) / 2;  // Index of midpoint
		Merge_sort(arr, first, mid, count_compare); // Sort left half
		Merge_sort(arr, mid + 1, last, count_compare); // Sort right half
		merge(arr, first, mid, last, count_compare); // Merge the two halves
	}
}

void NoOFCompare::Quick_sort(int* arr, int first, int last, unsigned long long& count_compare) {
	int pivot = arr[(first + last) / 2];
	int i = first, j = last;
	do {
		while (++count_compare && arr[i] < pivot) i++;
		while (++count_compare && arr[j] > pivot) j--;
		if (++count_compare && i <= j) {
			std::swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (++count_compare && i < j);
	if (++count_compare && first < j) Quick_sort(arr, first, j, count_compare);
	if (++count_compare && i < last) Quick_sort(arr, i, last, count_compare);
}

void NoOFCompare::Counting_sort(int* arr,int n, int u, unsigned long long &count_compare){
	int *output = new int [n];  
    int *count = new int [u + 1] {0}, i; 

    for (i = 0; ++count_compare && i < n; ++i) 
        ++count[arr[i]]; 

    for (i = 1; ++count_compare && i <= u; ++i) 
        count[i] += count[i - 1]; 
  
    for (i = 0; ++count_compare && i < n; ++i) { 
        output[count[arr[i]] - 1] = arr[i]; 
        --count[arr[i]]; 
    } 

    for (i = 0; ++count_compare && i < n; ++i) 
        arr[i] = output[i]; 

	delete []output, count;
}


void NoOFCompare::Radix_sort(int* arr,int n, unsigned long long &count_compare){
	int max_val = arr[0]; // get maximum value in the array
	for (int i = 1; ++count_compare && i < n; ++i)
		if (++count_compare && arr[i] > max_val){
            max_val = arr[i]; 
        } 

	int digits = 0, div;  // find the maximum number of digits
	do{
		digits++; 
		div = max_val / pow(10, digits); 
	} while (++count_compare && div > 0);

	int **tempArr = new int*[10]; // declare variables for temp store
	for (int i = 0; ++count_compare && i < 10; ++i)
		tempArr[i] = new int[n];
	int tempCount[10];

	// form groups of numbers and combine groups
    
	for (int i = 0; ++count_compare && i < digits ; ++i) {
		int exp = pow(10, i); 
        // reset the counting
        
		for (int j = 0; ++count_compare && j < 10; ++j){
            tempCount[j] = 0; 
        } 
        
		for (int j = 0; ++count_compare && j < n; ++j) { // form groups
			int idx = (arr[j] / exp) % 10; 
			tempArr[idx][tempCount[idx]++] = arr[j]; 
		}
		int idx = 0; // combine groups
		for (int j = 0; ++count_compare && j < 10; ++j){
            for (int k = 0; ++count_compare && k < tempCount[j]; ++k){
                arr[idx++] = tempArr[j][k];
            }	
        }
			
	}
}

void NoOFCompare::Flash_sort(int* arr, int n, unsigned long long &count_compare){
	
    int valueMin = arr[0];
    int max = 0;
    int m = int(0.45 * n);
    int* l = new int[m];

    for (int i = 0; ++count_compare && i < m; i++) 
        l[i] = 0;

    for (int i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && arr[i] < valueMin)
            valueMin = arr[i];
        if (++count_compare && arr[i] > arr[max])
            max = i;
    }
    if (++count_compare && arr[max] == valueMin)
        return;

    double c1 = (double)(m - 1) / (arr[max] - valueMin);

    for (int i = 0; ++count_compare && i < n; i++)
    {
        int k = int(c1 * (arr[i] - valueMin));
        ++l[k];
    }

    for (int i = 1; ++count_compare && i < m; i++) 
        l[i] += l[i - 1];
	
    std::swap(arr[max], arr[0]);

    int n_move = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (++count_compare && n_move < n - 1)
    {
        while (++count_compare && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (arr[j] - valueMin));
        }
        flash = arr[j];
        if (++count_compare && k < 0)
            break;
        while (++count_compare && j != l[k])
        {
            k = int(c1 * (flash - valueMin));
            --l[k];
            std::swap(flash, arr[l[k]]);
            ++n_move;
        }
    }

    for (int i = 1; ++count_compare && i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while ( ++count_compare && j >= 0 &&  ++count_compare && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }

    delete[] l;

}