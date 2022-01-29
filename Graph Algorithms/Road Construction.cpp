//video solution link : https://www.youtube.com/watch?v=Cwv0W02J0Q0&list=PL2q4fbVm1Ik4vJBWX1vgYbjIrfJdIfKgN&index=6

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
 
int _rank[N];
int par[N];
 
int find(int a){
	if(par[a] == -1) return a;
	
	return par[a] = find(par[a]);
}
 
int merge(int a , int b){
	
	a = find(a);
	b = find(b);
	
	if(_rank[a] < _rank[b]) swap(a , b);
	
	par[b] = a;
	_rank[a] += _rank[b];
	
	return _rank[a];
}
 
int main()
{
	int n , a , b , m;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) _rank[i] = 1 , par[i] = -1;
	
	int cc = n;
	int mx = 1;
	
	while(m--){
		cin>>a>>b;
		
		if(find(a) != find(b)) mx = max(mx , merge(a , b)) , cc--;
		
		cout<<cc<<" "<<mx<<endl;
	}
}
 
