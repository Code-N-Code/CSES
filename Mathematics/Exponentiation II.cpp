#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e9+7;

ll power(ll a, ll n , int mod){
	ll res = 1;

	while(n){
		if(n & 1) res = (res * a) % mod;

		n>>=1;
		a = (a * a) % mod;
	}

	return res;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		ll a , b , c;
		cin>>a>>b>>c;
		ll m = power(b , c , MOD-1);
//		cout<<m<<endl;
		cout<<power(a , m , MOD)<<endl;
	}
}
