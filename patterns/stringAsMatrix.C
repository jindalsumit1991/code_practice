// Example program
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str = "mynameissumitjindal";
  int r;
  cin >> r;
  for(int i=0; i<r; i++){
    for(int j=0; j<r; j++){
        cout << str[i+j*r] << " ";   
    }
    cout << endl;
  }
  return 0;
}
