#include <iostream>
// check log2base2video bubble sort
// if the array is already sorted then flag vlaue stays 0 and after the first iteration itself the function stops
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int flag(0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            // no swaps are done then no need to check for other iterations
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}