#include<iostream>

using namespace std;

bool minheap(int arr[],int n){
    bool flag;
    for(int i = 0 ; i <= (n-2)/2 ; i++){
        
        //leaf node
         if (arr[2*i +1] < arr[i]) 
            return false;
        if (2*i+2 < n && arr[2*i+2] < arr[i]) 
            return false; 
    }
    return true;
}

int main(){
    int arr[100];  int i,n;
    cout<<"Enter the array size : ";cin>>n; //
    cout<<"Enter the array : "<<endl;
   
    for(i = 0;i<n;i++){
        cin>>arr[i];
    }
    bool flagmin = minheap(arr,n);
    cout<<"The array is a heap : ";
    if( flagmin ){cout<<"Y"<<endl;}
    else {
        cout<<"N"<<endl;
        
    } 
     
    
    return 0;
}

