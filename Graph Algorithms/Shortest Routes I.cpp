#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
const int N = 2e5;
const ll INF = 1e18;
vector<pair<ll,ll> > adj[N+1];
ll dist[N+1];
 
void dijkstra(int n , int src){
	for(int i=1;i<=n;i++) dist[i] = INF;
 
	//preprocessing
	priority_queue< pair<ll,ll> , vector<pair<ll,ll> > , greater<pair<ll,ll> > > pq;
	dist[src] = 0;
	pq.push({0 , src});
 
	//processing
	while(pq.empty() == false){
		int node = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		
		if(dist[node] < d) continue;
 
		for(pair<ll,ll> edge : adj[node]){
			int v = edge.first;
			ll w = edge.second;
 
			if(dist[v] > d + w){
				dist[v] = d + w;
				pq.push({dist[v] , v});
			}
		}
 
	}
	
}
 
int main(){
	int n , m , src;
	ll a , b , w;
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin>>n>>m , src = 1;
 
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		adj[a].push_back({b , w});
	}
 
	dijkstra(n , src);
 
	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}
