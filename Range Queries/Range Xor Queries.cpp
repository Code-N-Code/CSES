//video solution link : https://www.youtube.com/watch?v=INkL6KOQTHc&list=PL2q4fbVm1Ik7RiRG7KnHjxmblwFEGfVdR&index=1

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
lli ar[N];
 
int main()
{
	int n , q , a , b;
	cin>>n>>q;
	
	REP(i , n) cin>>ar[i] , ar[i] ^= ar[i-1];
	
	while(q--)
	{
		cin>>a>>b;
		cout<<(ar[b] ^ ar[a-1])<<endl;
	}
}
 
