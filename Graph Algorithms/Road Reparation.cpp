//video solution link : https://www.youtube.com/watch?v=BDbXyrvwn1g&list=PL2q4fbVm1Ik4vJBWX1vgYbjIrfJdIfKgN&index=7

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
struct Edge{
	int a;
	int b;
	ll weight;
};
 
vector<Edge> edgeList;
int _par[200001];
 
bool comp(Edge a , Edge b){
	return a.weight < b.weight;
}
 
int find(int a){
	if(_par[a] == -1) return a;
	
	return _par[a] = find(_par[a]);
}
 
bool merge(int a , int b){
	a = find(a);
	b = find(b);
	
	if(a == b) return false;
	
	_par[a] = b;
	return true;
}
 
int main(){
	int n , m;
	ll res = 0;
	int addedEdgeCount = 0;
	Edge temp;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) _par[i] = -1;
	
	for(int i=1;i<=m;i++) cin>>temp.a>>temp.b>>temp.weight , edgeList.push_back(temp);
	
	sort(edgeList.begin() , edgeList.end() , comp);
	
	for(Edge e : edgeList){
		if(merge(e.a , e.b)) res += e.weight , addedEdgeCount++;
	}
	
	if(addedEdgeCount == n-1)
	cout<<res;
	else
	cout<<"IMPOSSIBLE";
}
 
