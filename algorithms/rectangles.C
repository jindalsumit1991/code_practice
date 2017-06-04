#include <iostream>
#include <string>
using namespace std;

bool checkOverlap(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
	if((bx1>ax2) || (ax1>bx2) || (ay2>by1) || (ay1<by2)){

		return false;
	}
	return true;
}

int main() {
    int ax1,ay1,ax2,ay2,bx1,by1,bx2,by2;
    cin>>ax1>>ay1>>ax2>>ay2>>bx1>>by1>>bx2>>by2;
    bool isOverlap = checkOverlap(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2);
    if(isOverlap)
        cout<<"true";
    else
        cout<<"false";
	
	return 0;
}
