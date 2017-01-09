#include <iostream>
#include "SortingAlgorithm.h"

using namespace std;

int binarySearch(int *arr, int size, int num, int beg, int end){
   if(beg==end && (arr[beg] != num))
	 return -1;
   int mid = (beg+end)/2;
   if(num==arr[mid])
      return mid;
   if(num<arr[mid])
      return binarySearch(arr, size, num, beg, mid-1);
   else
      return binarySearch(arr, size, num, mid+1, size-1);
   return -1;
}

int main() {

   int *arr;
   int size, element;
   cout<<"Enter size of array: ";
   cin>>size;
   arr = new int[size];
   cout<<"\nEnter elements of array:\n";
   for(int i=0; i<size; i++){
      cin>>arr[i];
   }

   //mergeSort(arr, 0, size-1);
   selectionSort(arr, size);
   cout<<"\nSorted array after merge sort: ";
   printArray(arr, size);
   cout<<endl;

   cout<<"Enter element to search: ";
   cin>>element;

   cout<<"Index is: "<<binarySearch(arr, size, element, 0, size)<<endl;

   return 0;
}
