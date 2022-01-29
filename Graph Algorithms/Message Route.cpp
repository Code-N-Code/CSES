//video solution link : https://www.youtube.com/watch?v=9I1LBFPW0iE&list=PL2q4fbVm1Ik4vJBWX1vgYbjIrfJdIfKgN&index=3

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
 
vector<int> ar[100001];
int dist[100001];
int par[100001];
bool vis[100001];
 
int n , m;
 
bool bfs(){
	queue<int> q;
	dist[1] = 1;
	vis[1] = 1;
	q.push(1);
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		if(node == n) return true;
		
		for(int u : ar[node])
		if(vis[u] == false){
			dist[u] = dist[node] + 1;
			vis[u] = true;
			par[u] = node;
			q.push(u);
		}
	}
	
	return false;
}
 
int main()
{
	int a , b;
	
	cin>>n>>m;
	
	REP(i , m) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	if(bfs()){
		cout<<dist[n]<<endl;
		
		int path = n;
		vector<int> res;
		while(path != 0) res.pb(path) , path = par[path];
		
		reverse(res.begin() , res.end());
		for(int node : res) cout<<node<<" ";
	}
	else cout<<"IMPOSSIBLE";
}
 
