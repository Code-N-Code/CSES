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
 
int price[1001];
int pages[1001];
int dp[1001][100001];
 
int main()
{
	int n , x;
	
	cin>>n>>x;
	REP(i , n) cin>>price[i];
	REP(i , n) cin>>pages[i] , dp[i][0] = 0;
	
	memset(dp , INF , sizeof dp);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=x;j++)
		{
			dp[i][j] = dp[i-1][j];
			
			if(j >= price[i])
			dp[i][j] = max(dp[i][j] , dp[i-1][j-price[i]] + pages[i]);
		}
	}
	
	int res = 0;
	REP(i , n) res = max(res , dp[i][x]);
	
	cout<<res;
}
 
