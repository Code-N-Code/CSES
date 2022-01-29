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
#define INF 2000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
 
const int N = 200001;
lli ar[N];
lli st[4*N];
 
int build(int si , int ss , int se)
{
	if(ss == se) return st[si] = ar[ss];
	
	int mid = (ss + se) >> 1;
	
	return st[si] = min(build(2*si , ss , mid) , build(2*si+1 , mid+1 , se));
}
 
void update(int si , int ss , int se , int idx , lli value)
{
	if(idx > se || idx < ss) return;
	
	if(ss == se && ss == idx){
		st[si] = value;
		return;
	}
	
	int mid = (ss + se) >> 1;
	update(2*si , ss , mid , idx , value);
	update(2*si+1 , mid+1 , se , idx , value);
	st[si] = min(st[2*si] , st[2*si+1]);
}
 
int getMin(int si , int ss , int se , int l , int r)
{
	if(l > se || r < ss) return INF;
	
	if(ss >= l && se <= r) return st[si];
	
	int mid = (ss + se) >> 1;
	return min(getMin(2*si , ss , mid , l , r) , getMin(2*si+1 , mid+1 , se , l , r));
}
 
int main()
{
	int n , q , a , b;
	cin>>n>>q;
	
	REP(i , n) cin>>ar[i];
	
	build(1 , 1 , n);
	while(q--)
	{
		int code;
		cin>>code>>a>>b;
		if(code == 1) update(1 , 1 , n , a , b);
		else		  cout<<getMin(1 , 1 , n , a , b)<<endl;
	}
}
 
