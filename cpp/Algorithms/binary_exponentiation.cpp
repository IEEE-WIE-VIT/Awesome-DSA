#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b) for(int i=a;i<b;i++)
#define FORE(a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define vl vector<ll>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);
#define mod 1e9+7
#define N 100005
#define gr vector<int> gr[N]
#define pinf INT_MAX
#define ninf INT_MIN
// Function to calculate a raised to the power b in O(logn)  
ll binpow(int a,int b){
	if(b==0)return 1;
	ll ans=binpow(a,b/2);
	if(b&1){
		return (a*ans);
	}
	return ans;
}
int main(){
	cout<<binpow(2,4);
}






