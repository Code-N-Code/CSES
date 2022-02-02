#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll res;
ll ar[21];

ll getCount(ll mask , ll k , ll n){
	ll sum = 0;
	int count = 0;
	ll prod = 1;

	for(int i=0;i<k;i++)
	if(mask & (1<<i)){
		count++;

		if(n / ar[i] < prod) return 0;

		prod *= ar[i];
	}
	sum = n / prod;
	return count % 2 ? sum : -sum;
}

int main(){
	ll n , k;
	cin>>n>>k;

	for(int i=0;i<k;i++) cin>>ar[i];

	ll mask = 1;

	while(mask < (1<<k)){
		res += getCount(mask , k , n);
		mask++;
	}

	cout<<res;
}
