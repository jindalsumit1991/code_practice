// Example program
#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(const string &str1, const string &str2){
    int l1 = str1.size();
    int l2 = str2.size();
    int j = 0;
    for(int i = 0; i<l2 && j<l1; i++){
        if(str1[j] == str2[i])
            j++;
    }
    return(l1 == j);
}

int main()
{
  string str1 = "sitnl";
  string str2 = "sumitjindal";
  
  cout << (isSubsequence(str1, str2) ? "yes" : "no");
  return 0;
}
