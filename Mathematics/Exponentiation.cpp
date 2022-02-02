#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;

int main(){
	int t;
	cin>>t;

	while(t--){
		long long int a , n , res = 1;

		cin>>a>>n;

		while(n){
			if(n & 1) res = (res * a)%mod;

			n >>= 1;
			a = (a * a) % mod;
		}

		cout<<res<<endl;
	}
}
