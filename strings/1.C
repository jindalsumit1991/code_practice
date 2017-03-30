
/*********************************************************************************

http://www.geeksforgeeks.org/count-substrings-with-same-first-and-last-characters/

---- Count substrings with same first and last characters. ----

We are given a string S, we need to find count of all contiguous substrings 
starting and ending with same character.

Examples :

Input  : S = "abcab"
Output : 7
There are 15 substrings of "abcab"
a, ab, abc, abca, abcab, b, bc, bca
bcab, c, ca, cab, a, ab, b
Out of the above substrings, there 
are 7 substrings : a, abca, b, bcab, 
c, a and b.

Input  : S = "aba"
Output : 4
The substrings are a, b, a and aba

**************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int countSubstr(const string &str)
{
    int count = str.size();
    for(int i=0; i<str.size(); i++)
    {
        for(int j=i+1; j<str.size(); j++)
        {
            if(str[i] == str[j])
                count++;
        }
    }
    return count;
}

int main()
{
    string str;
    cout << "Enter the input string: ";
    cin >> str;
    int count = countSubstr(str);
    cout << "Number of substrings is :" << count << endl;
    return 0;
}
