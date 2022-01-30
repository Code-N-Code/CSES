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
lli val[N];
int in[N];
int out[N];
int _t = 1;
int n;
 
lli bit[2*N];
 
void dfs(int node , int par)
{
	in[node] = _t++;
	
	for(int child : ar[node])
	if(child != par) dfs(child , node );
	
	out[node] = _t++;
}
 
void update(int i , lli dx){
	while(i <= 2*n)
	{
		bit[i] += dx;
		i += (i & -i);
	}
}
 
lli sum(int i)
{
	lli res = 0;
	while(i > 0)
	{
		res += bit[i];
		i -= (i & -i);
	}
	
	return res;
}
 
int main()
{
	lli m , a , b;
	cin>>n>>m;
	REP(i , n) cin>>val[i];
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	dfs(1 , 0);
	
	REP(i , n) update(in[i] , val[i]) , update(out[i] , -val[i]);
	
	while(m--)
	{
		int code;
		cin>>code;
		
		if(code == 1)
		{
			cin>>a>>b;
			update(in[a]  , b - val[a]);
			update(out[a] , val[a] - b);
			val[a] = b;
		}
		else
		cin>>a , cout<<sum(in[a])<<endl;
	}
}
 
