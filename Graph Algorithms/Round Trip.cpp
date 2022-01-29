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
vi temp , res;
bool vis[100001];
 
bool dfs(int node ,int par){
	vis[node] = true;
	temp.push_back(node);
	
	for(int v : ar[node])
	if(vis[v] == false){
		if(dfs(v , node) == true) return true;
	}
	else
	if(par != v){
		temp.push_back(v);
		return true;
	}
	
	temp.pop_back();
	return false;
}
 
int main()
{
	int n , m , a , b;
	cin>>n>>m;
	
	bool flag = false;
	
	REP(i , m) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	REP(i , n)
	if(vis[i] == false)
	{
		flag = dfs(i , -1);
		
		if(flag == true) break;
	}
	
	if(flag == false) cout<<"IMPOSSIBLE";
	else
	{
		int src = temp.back();
		res.pb(temp.back());
		temp.pop_back();
		
		
		while(1){
			res.pb(temp.back());
			
			if(temp.back() == src) break;
			
			temp.pop_back();
		}
		
		//printing
		cout<<res.size()<<endl;
		for(int node : res) cout<<node<<" ";
	}
	
}
 
