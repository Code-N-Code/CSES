//video solution link : https://www.youtube.com/watch?v=ONDFFcD6GXc&list=PL2q4fbVm1Ik7RiRG7KnHjxmblwFEGfVdR&index=3

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
 
const int N = 1001;
lli ar[N][N];
 
lli getAns(int sx , int sy , int ex , int ey)
{
	return ar[ex][ey] - ar[sx-1][ey] - ar[ex][sy-1] + ar[sx-1][sy-1];
}
int main()
{
	int n , q;
	int a , b , c , d;
	char ch;
	
	cin>>n>>q;
	
	REP(i , n) REP(j , n) cin>>ch , ar[i][j] = ch =='*' , ar[i][j] += ar[i][j-1];
	REP(i , n) REP(j , n) ar[i][j] += ar[i-1][j];
	
	while(q--)
	cin>>a>>b>>c>>d , cout<<getAns(a , b , c , d)<<endl;
}
 
