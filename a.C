#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int arr[6] = {2,6,1,5,4,3};

   for(int i=0; i<5; i++){
      int hole=i+1;
      int num = arr[hole];
      while(hole && num<arr[hole-1]){
	 arr[hole] = arr[hole-1];
	 hole--;
      }
      arr[hole] = num;
   }
   for(int i=0;i<6;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;
   return 0;
}
