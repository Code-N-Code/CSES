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
 
int sub[N];
int cnt[N];
bool vis[N];
vi ar[N];
lli res;
int n;
int k;
int mxHeight;
 
int subSize(int node , int par)
{
	sub[node] = 1;
	
	for(int child : ar[node])
	if(child != par && vis[child] == false)
	sub[node] += subSize(child , node);
	
	return sub[node];
}
 
int centroid(int node , int par , int limit)
{
	for(int child : ar[node])
	if(child != par && vis[child] == false && sub[child] >= limit)
	return centroid(child , node , limit);
	
	return node;
}
 
void update(int node , int par , bool add , int lvl = 1)
{
	if(lvl > k) return;
	
	if(add)  cnt[lvl]++;
	else	 res += cnt[k - lvl];
	mxHeight = max(mxHeight , lvl);
	
	for(int child : ar[node])
	if(vis[child] == false && child != par)
	update(child , node , add , lvl + 1);
}
 
void decompose(int node , int par)
{
	int c = centroid(node , par , subSize(node , par)/2);
	vis[c] = 1;
	
	cnt[0] = 1;
	mxHeight = 0;
	for(int child : ar[c])
	if(child != par && vis[child] == false)
	{
		update(child , c , false);
		update(child , c , true);
	}
	
	REP(i , mxHeight+1) cnt[i-1] = 0;
	
	for(int child : ar[c]) if(vis[child] == false) decompose(child , -1);
}
 
int main()
{
	int a , b;
	cin>>n>>k;
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	res = 0;
	decompose(1 , -1);
	cout<<res;
}
 
