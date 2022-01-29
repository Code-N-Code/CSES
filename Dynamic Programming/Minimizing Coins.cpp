//link to video solution : https://www.youtube.com/watch?v=m5uSidurbZ8&list=PL2q4fbVm1Ik7MOM34WOYlx_2hrsn-PQwa&index=1

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
 
int coins[101];
int dp[1000001];
int main()
{
	int n , x;
	cin>>n>>x;
	
	REP(i , n) cin>>coins[i];
	
	REP(i , x) dp[i] = INF;
	
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=n;j++)
		if(i - coins[j] >= 0)
		dp[i] = min(dp[i] , dp[ i - coins[j] ] + 1);
	}
	
	if(dp[x] == INF) dp[x] = -1;
	
	cout<<dp[x];
}
