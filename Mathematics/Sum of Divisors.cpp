#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int mod = 1e9+7;

long long res = 0;

long long firstHalf(long long n){
	long long i = 1;
	while(i*i <= n){
		long long temp = ((i % mod) * ((n/i) % mod)) % mod;
		res = (res + temp) % mod;
		i++;
	}

	return i;
}

long long getSum(long long L , long long R){
	L--;
	R = ((R % mod) * ((R + 1) % mod)) / 2;
	L = ((L % mod) * ((L + 1) % mod)) / 2;
	long long res = (R - L) % mod;
	if(res < 0) res += mod;
	return res;
}

int main(){
	long long n;
	cin>>n;

	long long L = firstHalf(n);
	long long curr = n / L;

	while(L <= n){
		long long count = n / curr - n / (curr+1);
		long long R = L + count - 1;

		long long temp = ((curr % mod) * getSum(L , R)) % mod;
		res = (res + temp) % mod;

		L = R + 1 , curr--;
	}

	cout<<res;
}
