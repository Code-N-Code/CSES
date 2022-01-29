//video solution link : https://www.youtube.com/watch?v=eeZxxor8el4&list=PL2q4fbVm1Ik4vJBWX1vgYbjIrfJdIfKgN&index=8

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int in_degree[100001];
vector<int> ar[100001];
 
void printOrder(int n){
	
	queue<int> q;
	vector<int> res;
	
	for(int i=1;i<=n;i++)
	if(in_degree[i] == 0) q.push(i);
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		res.push_back(node);
		
		for(int v : ar[node]){
			in_degree[v]--;
			if(in_degree[v] == 0) q.push(v);
		}
	}
	
	if(res.size() == n){
		for(int node : res) cout<<node<<" ";
	}
	else{
		cout<<"IMPOSSIBLE";
	}
}
 
int main(){
	int a , b , n , m;
	
	cin>>n>>m;
	
	for(int i=1;i<=m;i++) cin>>a>>b , ar[a].push_back(b) , in_degree[b]++;
	
	printOrder(n);
}
 
