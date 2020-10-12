#include <iostream>

using namespace std;
#define endl '\n'

bool compare(int a, int b)
{
    return a > b;
}

int main()
{

    int n;
    cin >> n;

    int arr[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // during this pandemic if you can laugh hard on a normal call with your friends then surely you have got some awesome mates
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    putchar('\n');
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}