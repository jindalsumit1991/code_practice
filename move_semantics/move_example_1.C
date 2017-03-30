#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class A
{
private:    
    int *ptr;
    int memlength = 1000;
    int a = 10;

public:
    //Default constructor
    A()
    {
        cout << "Default constructor called" << endl;
        ptr = new int[memlength];
    }

    //Copy constructor
    A(const A &other)
    {
        cout << "Copy constructor called" << endl;
        ptr = new int[memlength];
        memcpy(ptr, other.ptr, sizeof(int)*memlength);
    }

    //Move constructor
    A(A && other):ptr(other.ptr)
    {
        cout << "move constructor called" << endl;
        other.ptr = nullptr;
    }

    //Overloading less-than operator to support sort
    bool operator < (const A &other)
    {
        return a>other.a ? true : false;
    }

    //Move assignment operator
    A & operator = (A && other)
    {
        cout << "move assignment" << endl;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }
};

int main()
{
    vector<A> v(5);
    sort(v.begin(), v.end());
    return 0;
}
