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
 
int dp[1000001];
int main()
{
	int n;
	cin>>n;
	
	REP(i , 10) dp[i-1] = 1;
	
	for(int i=10;i<=n;i++) dp[i] = INF;
	
	for(int i=10;i<=n;i++)
	{
		int temp = i;
		
		while(temp)
		{
			int d = temp % 10;
			temp /= 10;
			
			if(d == 0) continue;
			
			dp[i] = min(dp[i] , dp[i - d] + 1);
		}
	}
	
	cout<<dp[n];
}
 
