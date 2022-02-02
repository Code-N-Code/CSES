#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9+7;

ll fact(ll n){
	ll res = 1;

	for(int i=1;i<=n;i++) res = (res * i) % mod;

	return res;
}

ll power(ll a , ll n){
	ll res = 1;

	while(n){
		if(n & 1) res = (res * a) % mod;

		n >>= 1;
		a = (a * a) % mod;
	}

	return res;
}

ll modInv(ll n){
	return power(n , mod-2);
}

ll C(ll n , ll r){
	if(r > n) return 0;

	ll res = fact(n);
	res = (res * modInv(fact(r))) % mod;
	res = (res * modInv(fact(n - r))) % mod;

	return res;
}

int main(){
	int n , m;

	cin>>n>>m;

	cout<<C(n + m - 1 , m);
}
