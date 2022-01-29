//video solution link : https://www.youtube.com/watch?v=9u0WUGL8OS8&list=PL2q4fbVm1Ik4vJBWX1vgYbjIrfJdIfKgN&index=2

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
 
vi ar[100001];
bool vis[100001];
 
void dfs(int node){
	vis[node] = 1;
	
	for(int child : ar[node])
	if(vis[child] == 0) dfs(child);
}
 
int main()
{
	int n , m , a , b;
	
	vi res;
	
	cin>>n>>m;
	REP(i , m) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	REP(i , n)
	if(vis[i] == 0)
	dfs(i) , res.pb(i);
	
	cout<<res.size()-1<<endl;
	for(int i=1;i<res.size();i++)
	cout<<res[i-1]<<" "<<res[i]<<endl;
}
 
