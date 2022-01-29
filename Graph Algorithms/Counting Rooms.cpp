//video solution link : https://www.youtube.com/watch?v=QrZAee1PZBE&list=PL2q4fbVm1Ik4vJBWX1vgYbjIrfJdIfKgN&index=1

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
bool vis[1001][1001];
int N , M;
 
bool isValid(int x , int y)
{
	if(x < 1 || x > N || y < 1 || y > M) return false;
	
	if(vis[x][y] == true || ar[x][y] == '#') return false;
	
	return true;
}
 
void dfs(int x , int y)
{
	vis[x][y] = true;
	
	if(isValid(x-1 , y))
	dfs(x-1 , y);
	
	if(isValid(x , y + 1))
	dfs(x , y + 1);
	
	if(isValid(x + 1 , y))
	dfs(x + 1 , y);
	
	if(isValid(x , y-1))
	dfs(x , y - 1);
}
 
int main()
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		cin>>ar[i][j];
	}
	
	int cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		if(ar[i][j] == '.' && vis[i][j] == false)
		dfs(i , j) , cnt++;
	}
	
	cout<<cnt;
}
 
