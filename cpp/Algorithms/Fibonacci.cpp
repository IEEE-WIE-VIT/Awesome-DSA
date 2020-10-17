#include <iostream>
using namespace std;

/* Fibonacci using three variables
   time complexity : O(N)  
   space compexity : O(1) 
*/
int fib(int n) { 
    int a = 0, b = 1, c, i; 
    if( n == 0) return a; 
    for(i = 2; i <= n; i++) {
       c = a + b; 
       a = b; 
       b = c; 
    } 
    return b; 
} 
/* Fibonacci using recursion
   time complexity : O(2^N)  T(n) = T(n-1) + T(n-2)
   space compexity : O(N) if stack memeory considered
*/
int fib_rec(int N){
    if(N<=1) return N;
    return fib(N-1)+fib(N-2);
}
/* Fibonacci using dynamic programming 
   time complexity : O(N)  
   space compexity : O(N) 
*/
int fib_dp(int N){
    int f[N+1];
    f[0]=0; f[1]=1;
    for(int i=2;i<=N;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[N];
}

int main()
{
   int n = 9; 
   cout<< "Fibonacci using three variables: ";
    cout << fib(n)<<endl; 
    cout<< "Fibonacci using recursion: ";
    cout << fib_rec(n)<<endl; 
    cout<< "Fibonacci using dynamic programming : ";
    cout << fib_dp(n)<<endl; 
    return 0; 
   
   return 0;
}
