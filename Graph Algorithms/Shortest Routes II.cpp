#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
const ll INF = 1e15;
const int N = 500;
ll dist[N+1][N+1];
 
int main(){
	int n , m , q , a , b , c;
	
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) i == j ? dist[i][j] = 0 : dist[i][j] = INF;
	
	for(int i=1;i<=m;i++) {
		cin>>a>>b>>c;
		if(dist[a][b] > c) dist[a][b] = c , dist[b][a] = c;
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
		}
	}
	
	while(q--){
		cin>>a>>b;
		cout<<(dist[a][b] != INF ? dist[a][b] : -1)<<endl;
	}
}
 
