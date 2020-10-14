/*
    you are given a sorted array an you have to find all the pairs that are equal to a sum k
    note if you want to increment csum value increment start 
    if you want to decrease csum value the decrement end 
*/

#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{

    int n;
    cin >> n;

    vector<int> v(n, 0);

    for (auto &i : v)
    {
        cin >> i;
    }

    int k;
    cin >> k; // target sum

    // so our method is two pointer method
    // we keep one pointer at the start and one at the end
    // more explanation is in the book

    int start = 0;
    int end = n - 1;
    int csum(0);

    while (start < end)
    {
        csum = v[start] + v[end];

        if (csum == k)
        {
            cout << v[start] << " " << v[end] << endl;
            start++;
            end--;
        }
        else if (csum > k)
        {
            // decrement end  pointer
            end--;
        }
        else
        {
            // csum < k
            // increment start pointer
            start++;
        }
    }

    return 0;
}