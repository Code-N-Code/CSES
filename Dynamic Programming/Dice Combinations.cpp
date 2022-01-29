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
 
lli dp[1000001];
int c[7];
int main()
{
	int n;
	cin>>n;
	REP(i , 6) c[i] = i;
	
	dp[0] = 1;
	
	REP(i , n)
	{
		for(int j=1;j<=6;j++)
		if(c[j] <= i) dp[i] += dp[i - c[j]] , dp[i] %= mod;
	}
	
	cout<<dp[n];
}
