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
 
const int N = 200001;
const int maxN = 21;
 
vi ar[N];
int br[N];
int in[N];
int sub[N];
int level[N];
int LCA[N][maxN];
int _t = 1;
lli res[N];
 
void dfs(int node , int par , int lvl)
{
	br[_t] = node;
	in[node] = _t++;
	sub[node] = 1;
	level[node] = lvl;
	LCA[node][0] = par;
	
	for(int child : ar[node])
	if(child != par)
	dfs(child , node , lvl + 1) , sub[node] += sub[child];
	
}
 
void preProcess(int n)
{
	for(int j=1;j<maxN;j++)
	{
		for(int i=1;i<=n;i++)
		if(LCA[i][j-1] != -1)
		{
			LCA[i][j] = LCA[LCA[i][j-1]][j-1];
		}
	}
}
 
int getLCA(int a, int b)
{
	if(level[a] > level[b])
		swap(a , b);
		
	int d = level[b] - level[a];
	
	for(int i=0; i<maxN; i++) if( (d>>i)&1 ) b = LCA[b][i];
	
	if(a == b)
		return a;
		
	for(int i=maxN-1;i>=0;i--)
	if(LCA[a][i] != LCA[b][i])
		a = LCA[a][i] , b = LCA[b][i];
	
	return LCA[a][0];
}
 
int main()
{
	int n , m , a , b;
	cin>>n>>m;
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	memset(LCA , -1 , sizeof LCA);
	dfs(1 , 0 , 0);
	LCA[1][0] = -1;
	preProcess(n);
	
	while(m--)
	{
		cin>>a>>b;
		if(level[a] > level[b]) swap(a , b);
		int lca = getLCA(a , b);
		int lcaPar = LCA[lca][0];
		
		if(lca == a)
		{
			res[in[lcaPar]]--;
			res[in[b]]++;
		}
		else
		{
			res[in[a]]++;
			res[in[b]]++;
			res[in[lca]]--;
			res[in[lcaPar]]--;
		}
	}
	
	
	lli ans = 0;
	res[0] = 0;
	REP(i , n) res[i] += res[i-1];
	
	
	REP(i , n)
	{
		int l = in[i];
		int dx = sub[i];
		
		cout<<res[l+dx-1] - res[l - 1]<<" ";
	}
}
 
