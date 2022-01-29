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
 
int st[4*N];
int ar[N];
int res;
 
int build(int si , int ss ,int se)
{
	if(ss == se) return st[si] = 1;
	
	int mid = (ss + se) / 2;
	return st[si] = build(2*si , ss , mid) + build(2*si + 1, mid + 1 , se);
}
 
void update(int si , int ss , int se , int val)
{
	if(ss == se)
	{
		res = ss;
		st[si] = 0;
		return;
	}
	
	int mid = (ss + se) / 2;
	if(st[2*si] >= val) update(2*si , ss , mid , val);
	else				update(2*si + 1 , mid + 1 , se , val - st[2*si]);
	
	st[si] = st[2*si] + st[2*si+1];
}
 
int main()
{
	int n , a;
	cin>>n;
	REP(i , n) cin>>ar[i];
	
	build(1 , 1 , n);
	
	REP(i , n)
	{
		cin>>a;
		update(1 , 1 , n , a);
		cout<<ar[res]<<" ";
	}
}
 
