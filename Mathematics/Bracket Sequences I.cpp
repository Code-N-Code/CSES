#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 1e9+7;

ll power(ll a , ll n){
	ll res = 1;

	while(n){
		if(n & 1) res = (res * a) % mod;

		n >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

ll fact(ll n){
	ll res = 1;

	for(int i=1;i<=n;i++) res = (res * i) % mod;

	return res;
}

ll catlan(ll n){
	ll res = (fact(2*n) * power(fact(n) , mod-2)) % mod;

	return (res * power(fact(n + 1) , mod-2)) % mod;
}

int main(){
	ll n;
	cin>>n;

	if(n % 2) cout<<0;
	else
	cout<<catlan(n/2);
}
