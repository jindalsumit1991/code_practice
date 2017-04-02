#include <iostream>

using namespace std;

typedef long numType;

numType factorial (numType n)
{
    numType lookup[n+1];
    lookup[0] = 1;
    lookup[1] = 1;
    for(numType i=2; i<=n; i++)
        lookup[i] = i*lookup[i-1];

    return lookup[n];
}

int main()
{
    numType num;
    cout << "Enter number whose factorial you want: ";
    cin >> num;
    cout << "\nFactorial is: " << factorial(num) << endl;
    return 0;
}
