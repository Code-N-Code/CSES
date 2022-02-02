#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll ar[1000001];
int main(){
	int n , x;
	cin>>n;

	for(int i=1;i<=n;i++) cin>>x , ar[x]++;

	for(int i=1;i<=1000000;i++){
		for(int j=i+i;j<=1000000;j+=i)
		ar[i] += ar[j];
	}

	for(int i=1000000;i>=1;i--){
		ar[i] = (ar[i] * (ar[i]-1)) / 2;
		for(int j=i+i;j<=1000000;j+=i)
		ar[i] -= ar[j];
	}

	cout<<ar[1];
}
