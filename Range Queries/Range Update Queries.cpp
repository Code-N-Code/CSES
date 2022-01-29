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
lli lazy[5*N];
 
lli build(int si , int ss , int se)
{
	if(ss == se) return st[si] = ar[ss];
	
	int mid = (ss + se) >> 1;
	
	return st[si] = build(2*si , ss , mid) + build(2*si+1 , mid+1 , se);
}
 
void clearLazy(int si)
{
	st[si] += lazy[si];
	lazy[2*si] += lazy[si];
	lazy[2*si+1] += lazy[si];
	lazy[si] = 0;
}
 
void addLazy(int si , lli value)
{
	lazy[2*si] += value;
	lazy[2*si+1] += value;
}
 
void update(int si , int ss , int se , int l , int r , lli value)
{
	clearLazy(si);
	if(l > se || r < ss) return;
	
	if(ss >= l && se <= r){
		st[si] += value;
		addLazy(si , value);
		return;
	}
	
	int mid = (ss + se) >> 1;
	update(2*si , ss , mid , l , r , value);
	update(2*si+1 , mid+1 , se , l , r , value);
	st[si] = st[2*si] + st[2*si+1];
}
 
lli getSum(int si , int ss , int se , int l , int r)
{
	clearLazy(si);
	if(l > se || r < ss) return 0;
	
	if(ss >= l && se <= r) return st[si];
	
	int mid = (ss + se) >> 1;
	return getSum(2*si , ss , mid , l , r) + getSum(2*si+1 , mid+1 , se , l , r);
}
 
int main()
{
	int n , q , a , b;
	lli dx;
	cin>>n>>q;
	
	REP(i , n) cin>>ar[i];
	
	build(1 , 1 , n);
	while(q--)
	{
		int code;
		cin>>code;
		if(code == 1) cin>>a>>b>>dx , update(1 , 1 , n , a , b , dx);
		else		  cin>>a , cout<<getSum(1 , 1 , n , a , a)<<endl;
	}
}
 
