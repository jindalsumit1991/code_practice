#include <iostream>
#include <ctime>

using namespace std;

typedef long numType;

numType fib(numType n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1) + fib(n-2);
}

int main()
{
    numType num;
    cout << "Enter the position of fibonacci term: ";
    cin >> num;
    int start = clock();
    cout << "\nFibonacci term is: " << fib(num) << endl;
    int stop = clock();
    cout << "Time taken: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 <<" ms" << endl;
    return 0;
}
