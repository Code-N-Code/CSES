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
 
char ar[1001][1001];
lli dp[1001][1001];
 
int main()
{
	int n;
	cin>>n;
	REP(i , n) REP(j , n) cin>>ar[i][j];
	
	if(ar[1][1] != '*')
	dp[1][1] = 1;
	
	REP(i , n)
	{
		REP(j , n)
		{
			if(ar[i][j] == '*') continue;
			
			if(i > 1) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
			if(j > 1) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
		}
	}
	
	cout<<dp[n][n];
}
 
