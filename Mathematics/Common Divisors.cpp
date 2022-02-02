#include<bits/stdc++.h>

using namespace std;
int ar[1000001];
int main(){
	int n , x;
	cin>>n;

	for(int i=1;i<=n;i++) cin>>x , ar[x]++;

	for(int i=1000000;i>=1;i--){
		int count = 0;
		for(int j=i;j<=1000000;j+=i)
		count+=ar[j];

		if(count > 1){
			cout<<i;
			return 0;
		}
	}
}
