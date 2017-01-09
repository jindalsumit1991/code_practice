#include <iostream>
#include "SortingAlgorithm.h"

using namespace std;

int kadaneImproved(int *arr, int size){
   int sum=arr[0], ans=arr[0];
   for(int i=1; i<size; i++){
      sum = (sum+arr[i] > arr[i]) ? sum+arr[i] : arr[i];
      ans = ans>sum ? ans : sum;
   }
   return ans;
}

int main() {

   int *arr;
   int size;
   cout<<"Enter size of array: ";
   cin>>size;
   cout<<"\nEnter elements of array:\n";
   for(int i=0; i<size; i++){
      cin>>arr[i];
   }
   int ans = kadaneImproved(arr, size);
   cout<<"\nMaximum sum is: "<<ans;
   cout<<endl;
   return 0;
}
