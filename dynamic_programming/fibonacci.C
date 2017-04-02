#include <iostream>
#include <ctime>

using namespace std;

typedef long numType;

numType fib(numType n)
{
    numType lookup[n+1];
    lookup[0] = 0;
    lookup[1] = 1;
    for(numType i=2; i<=n; i++)
        lookup[i] = lookup[i-2] + lookup[i-1];

    return lookup[n];
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
