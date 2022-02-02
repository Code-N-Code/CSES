#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e6;
const int mod = 1e9+7;

ll fact[N+1];
ll invFact[N+1];

ll power(ll a , ll n){
	ll res = 1;
	while(n){
		if(n & 1) res = (res * a) % mod;

		n >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

void init(){
	fact[0] = invFact[0] = 1;
	for(int i=1;i<=N;i++)
	{
		fact[i] = (fact[i-1] * i) % mod;
		invFact[i] = power(fact[i] , mod-2);
	}
}

ll C(int a , int b){
	ll res = (fact[a] * invFact[b]) % mod;
	   res = (res * invFact[a - b]) % mod;

	return res;
}

int main(){
	init();

	int a , b , n;

	cin>>n;
	while(n--){
		cin>>a>>b;
		cout<<C(a , b)<<"\n";
	}
}
