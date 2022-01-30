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
int n;
 
vi ar[N];
 
int sub[N];
int level[N];
int p[N];
int val[N];
 
//HLD
int chainHead[N];
int chainPos[N];
int nodeAtPos[N];
int chainNo = 1, ptr;
 
//st
int st[1<<19];
 
void dfs(int node , int par , int lvl)
{
	sub[node] = 1;
	level[node] = lvl;
	p[node] = par;
	
	for(int child : ar[node])
	if(child != par) dfs(child , node , lvl + 1);
}
 
 
//HLD
void hld(int node , int par , int head)
{
	chainHead[node] = head;
	
	chainPos[node] = ++ptr;
	nodeAtPos[ptr] = node;
	
	int mx = -1 , cNode = 0;
	
	for(int child : ar[node])
	if(sub[child] > mx && child != par) mx = sub[child] , cNode = child;
	
	if(mx > 0) hld(cNode , node , head);
	
	for(int child : ar[node])
	if((child != par) && (child != cNode))
	{
		chainNo++;
		hld(child , node , child);
	}
}
 
//segment tree
 
int build(int si , int ss , int se)
{
	if(ss == se)
	return st[si] = val[nodeAtPos[ss]];
	
	int mid = (ss + se) >> 1;
	
	return st[si] = max(build(si<<1 , ss , mid) , build((si<<1) + 1 , mid + 1 , se));
}
 
void update(int si , int ss , int se , int qi , int val)
{
	if(ss > qi || se < qi) return;
	
	if(ss == qi && se == qi)
	{
		st[si] = val;
		return;
	}
	
	int mid = (ss + se) >> 1;
	
	if(qi <= mid)
	update(si << 1 , ss , mid , qi , val);
	else
	update((si << 1) + 1 , mid + 1 , se , qi , val);
	
	st[si] = max(st[si << 1] , st[(si << 1)  + 1]);
}
 
int getMax(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si];
	
	int mid = (ss + se) >> 1;
	int L = getMax(si << 1 , ss , mid , qs , qe);
	int R = getMax((si << 1) + 1 , mid + 1 , se , qs , qe);
	
	return max(L , R);
}
 
int getAns(int a , int b)
{
	int chainA;
	int chainB;
	int ans = 0;
	
	while(1){
		
		if(level[chainHead[a]] > level[chainHead[b]]) swap(a , b);
		chainA = chainHead[a];
		chainB = chainHead[b];
		
		if(chainA == chainB){
			if(level[a] > level[b]) swap(a , b);
			ans = max(ans , getMax(1 , 1 , n , chainPos[a] , chainPos[b]));
			break;
		}
		
		ans = max(ans , getMax(1 , 1 , n , chainPos[chainB] , chainPos[b]));
		b = p[chainB];
	}
	
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a , b , q;
	cin>>n>>q;
	REP(i , n) cin>>val[i];
	
	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	memset(chainHead , -1 , sizeof chainHead);
	
	dfs(1 , -1 , 0);
	hld(1 , -1 , 1);
	
	build(1 , 1 , n);
	
	while(q--)
	{
		int code;
		cin>>code;
		
		if(code == 2)
		{
			cin>>a>>b;
			
			int ans = getAns(a , b);
			cout<<ans<<" ";
		}
		else
		{
			cin>>a>>b;
			update(1 , 1 , n , chainPos[a] , b);
		}
	}
	
	cout<<"\n";
}

