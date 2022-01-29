//video solution link : https://www.youtube.com/watch?v=rRhWyZXmEcQ&list=PL2q4fbVm1Ik7MOM34WOYlx_2hrsn-PQwa&index=2

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int dp[100001];
int main(){
	int ar[101] , n;
	vector<int> result;
	dp[0] = 1;
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>ar[i];
	
	for(int i=1;i<=n;i++){
		int d = ar[i];
		
		for(int j=100000;j-d>=0;j--)
		if(dp[j-d] == 1) dp[j] = 1;
	}
	
	for(int i=1;i<=100000;i++) if(dp[i] == 1 ) result.push_back(i);
	
	cout<<result.size()<<endl;
	for(int sum : result) cout<<sum<<" ";
}
 
