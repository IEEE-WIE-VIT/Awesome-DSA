#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n;
    cout<<"Enter Array Size:";
    cin>>n;
    int arr[n];
    cout<<"Enter Array Elements:"<<endl;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    cout<<"Sorted Array is:";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
