#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int mod = 1e9+7;

int main(){
	ll n;
	cin>>n;

	ll a = 0;
	ll b = 1;

	for(int i=3;i<=n+1;i++){
		ll c = (((i-1) % mod) * ((a + b) % mod)) % mod;
		a = b;
		b = c;
	}

	cout<<a;
}
