// Example program
#include <iostream>
#include <string>

using namespace std;

bool isSubstring(const string &str1, const string &str2){
    int l1 = str1.size();
    int l2 = str2.size();
    int j = 0;
    int i = 0;
    for(i = 0; i<l2; i++){
        if(str1[j] == str2[i])
            break;
    }
    
    if(i >= l2-l1-1)
        return false;
    
    for(j=0; j<l1 && i<l2; j++, i++){
        if(str1[j] != str2[i])
            return false;
    }
    return true;
}

int main()
{
  string str1 = "sumit";
  string str2 = "sumitjindal";
  
  cout << (isSubstring(str1, str2) ? "yes" : "no");
  return 0;
}
