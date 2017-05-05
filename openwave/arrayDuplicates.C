/* **********************************************
 *
 * Given an array of integers, print the number of
 * duplicate items in the array
 *
 * *********************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> IntArray;

int countDuplicates(IntArray arr)
{
    int count = 0;

    //Associative data structure to keep track of count of
    //occurence of each element (element is key, count is value)
    unordered_map<int,int> map;

    //Fill the hashmap as per counts
    //If the element does not exist, make a new entry
    //else increment the count.
    for(auto it = arr.begin(); it < arr.end(); it++)
    {
        if(map.find(*it) == map.end())
            map[*it] = 0;
        else
            map[*it]++;
    }
    
    //If the count of any key is > 0, it is a duplicate
    for(auto it = map.begin(); it != map.end(); it++)
    {
        if(it->second > 0)
            count++;
    }
    return count;
}
int main()
{
    int N;
    cout << "Input size of array: ";
    cin >> N;
    IntArray arr(N);

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    cout << "Number of duplicates: " << countDuplicates(arr) << endl;
    return 0;
}
