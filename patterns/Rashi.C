#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);

    int max = -1;
    for(int i=0; i<v.size(); i++)
    {
        if(max < v[i])
            max = v[i];
    }
/*    
    int **arr = new int*[max];
    for(int i=0; i<max; i++)
    {
        arr[i] = new int[v.size()];
    }

    for(int i=0; i<max; i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            arr[i][j] = 0;
        }
    }

    for(int j=0; j<v.size(); j++)
    {
        for(int i=(max-v[j]); i<max; i++)
        {
            arr[i][j] = 1;
        }
    }

    for(int i=0; i<max; i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            if(arr[i][j] == 0)
                cout << " " << " ";
            else
                cout << "*" << " ";
        }
        cout << endl;
    }
*/

    cout << endl << endl;

    for(int i=0; i<max; i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            if(max-v[j]-i > 0)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    return 0;
}

