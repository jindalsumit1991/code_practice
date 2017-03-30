#include <iostream>
#include "SortingAlgorithm.h"

using namespace std;

int kadaneImpl(int *arr, int size){
   int sum=0, ans=0;
   for(int i=0; i<size; i++){
      if(sum + arr[i]>0)
	 sum += arr[i];
      else
	 sum = 0;
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
   int ans = kadaneImpl(arr, size);
   cout<<"\nMaximum sum is: "<<ans;
   cout<<endl;
   return 0;
}
