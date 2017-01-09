#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include "SortingAlgorithm.h"

using namespace std;

//Common method for printing array
void printArray(const int *arr, int size){
   for(int i=0; i<size; i++){
      std::cout<<arr[i]<<"  ";
   }
   std::cout<<std::endl;
}


/* Selection Sort 
  - better if we keep track of min value's index
  - With first pass, index 0 will have the minimum value
  - With every pass, the left part of array will keep on sorted
  - Finally whole array will become sorted
  - Time Complexity - O(n^2)
  - Space complexity - O(1) - In-place algorithm
*/
void selectionSort(int *arr, int size){
   int min;
   for(int i=0; i<size; i++){
      for(int j=i+1; j<size; j++){
         if(arr[i] > arr[j]){
            min = arr[j];
	    arr[j] = arr[i];
            arr[i] = min;
	 }
      }
   }
}

/* Bubble Sort
 - Compare each element with the next adjacent element
 - If next element is smaller, swap the two elements
 - This will keep pushing the largest element towards end
 - After first pass, the largest element will be at the end of the array
*/
void bubbleSort(int *arr, int size){
   for(int i=0; i<size-1; i++){
      int flag = false;
      for(int j=0; j<size-i-1; j++){
          if(arr[j] > arr[j+1]){
              int temp = arr[j];
	      arr[j] = arr[j+1];
	      arr[j+1] = temp;
	      //set flag to indicate that a swap was performed during first pass
	      flag = true;
	  }
	  //if no swap was made in first pass, list is already sorted
	  if(!flag)
	     break;
      }
   }
}


/* Insertion Sort
 - The concept of creating a hole (youtube - mycodingschool channel)
 - We logically divide array into two subsets - left one is sorted one, right one is unsorted
 - We pick an element, say i+1, kind-of making a hole at that index and store it in var "value"
 - We compare "value" with element just behind it
 - If previous element is greater, move the previous one to right by 1
 - Move hole index to left by 1
 - Keep on comparing value at hole index to previous element till we reach 0th index
 - When done, put the "value" at hole index.
*/
void insertionSort(int *arr, int size){
   for(int i=0; i<size-1; i++){
      int hole = i+1;
      int value=arr[hole];
      while(hole>0 && value < arr[hole-1]){
	 arr[hole] = arr[hole-1];
	 hole--;
      }
      arr[hole] = value;
   }
}


/* Merge Sort
 - A divide-and-conquer sorting algorithm
*/

//Function to merge the recursively-split arrays in a sorted manner
void mergeSubArrays(int *arr, int left, int mid, int right) {
   int i,j,k,n1,n2;
   n1 = mid-left+1;
   n2 = right-mid;
   int ar_a[n1], ar_b[n2];
   for(i=0; i<n1; i++){
      ar_a[i] = arr[left+i];
   }
   for(i=0; i<n2; i++){
      ar_b[i] = arr[mid+1+i];
   }
   i=0;
   j=0;
   k=left;
   while(i<n1 && j<n2){
      if(ar_a[i] <= ar_b[j]){
	 arr[k] = ar_a[i];
	 i++;
      }
      else{
	 arr[k] = ar_b[j];
	 j++;
      }
      k++;
   }
   while(i<n1){
      arr[k] = ar_a[i];
      i++;
      k++;
   }
   while(j<n2){
      arr[k] = ar_b[j];
      j++;
      k++;
   }
}

//Function to break main array to two halves, recursively (till length of array is 1)
void mergeSort(int *arr, int leftOfArray, int rightOfArray) {
   if(leftOfArray < rightOfArray) {
      int mid = (leftOfArray + rightOfArray)/2;
      mergeSort(arr, leftOfArray, mid);
      mergeSort(arr, mid+1, rightOfArray);
      mergeSubArrays(arr, leftOfArray, mid, rightOfArray);
   }
}

#endif
