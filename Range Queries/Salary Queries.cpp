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
const int MX = 4e5 + 5;
struct Query{
	char t;
	int a;
	int b;
};
 
int ar[N];
vi val;
Query q[N];
lli BIT[MX];
 
void update(int i , lli dx){
	while(i <= MX)
	{
		BIT[i] += dx;
		i += (i & -i);
	}
}
 
lli sum(int i)
{
	lli res = 0;
	while(i > 0)
	{
		res += BIT[i];
		i -= (i & -i);
	}
	
	return res;
}
 
int position(int x)
{
	int ind = upper_bound(val.begin(), val.end(), x) - val.begin();
	
	return ind;
}
 
int main()
{
	int n , t , a , b;
	cin>>n>>t;
	REP(i , n) cin>>ar[i] , val.pb(ar[i]);
	
	REP(i , t)
	{
		cin>>q[i].t>>q[i].a>>q[i].b;
		
		if(q[i].t == '!') val.pb(q[i].b);
	}
	
	sort(val.begin() , val.end());
	val.erase(unique(val.begin() , val.end()) , val.end());
	
	
	REP(i , n) update(position(ar[i]) , 1);
	
	REP(i , t)
	{
		if(q[i].t == '?') cout<<sum(position(q[i].b)) - sum(position(q[i].a - 1))<<endl;
		else{
			update(position(ar[q[i].a]) , -1);
			ar[q[i].a] = q[i].b;
			update(position(ar[q[i].a]) , 1);
		}
	}
	
}
 
