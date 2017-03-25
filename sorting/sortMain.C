#include <iostream>
#include "SortingAlgorithm.h"

using namespace std;

int main() {

   int *arr;
   int size;
   cout<<"Enter size of array: ";
   cin>>size;
   arr = new int[size];
   cout<<"\nEnter elements of array:\n";
   for(int i=0; i<size; i++){
      cin>>arr[i];
   }
   /*
   selectionSort(arr, size);
   cout<<"\nSorted array after selection sort: ";
   printArray(arr, size);

   bubbleSort(arr, size);
   cout<<"\nSorted array after bubble sort: ";
   printArray(arr, size);

   insertionSort(arr, size);
   cout<<"\nSorted array after insertion sort: ";
   printArray(arr, size);
   cout<<endl;
   */

   mergeSort(arr, 0, size-1);
   cout<<"\nSorted array after merge sort: ";
   printArray(arr, size);
   cout<<endl;
   return 0;
}
