#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;

    bool arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = true;
    }

    arr[0] = false;
    arr[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (arr[i])
        {
            // better optimization is j = 2*i but not the best
            for (int j = 2 * i; j < n; j += i)
            {
                arr[j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == true)
        {
            cout << i << " ";
        }
    }

    return 0;
}