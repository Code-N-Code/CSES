#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
const int N = 2e5;
const int INF = 1e9;
int ar[N+1];
int pre[4*N] , suff[4*N];
 
void build(int si , int ss , int se){
	if(ss == se){
		pre[si] = ar[ss] - ss;
		suff[si] = ar[ss] + ss;
		return;
	}
	
	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si + 1 , mid + 1 , se);
	pre[si] = min(pre[2*si] , pre[2*si+1]);
	suff[si] = min(suff[2*si] , suff[2*si+1]);
}
 
void update(int si , int ss , int se , int qi , int val){
	if(ss > qi || se < qi) return;
	
	if(ss == se && ss == qi){
		ar[ss] = val;
		pre[si] = val - ss;
		suff[si] = val + ss;
		return;
	}
	
	int mid = (ss + se) / 2;
	update(2*si , ss , mid , qi , val);
	update(2*si+1 , mid+1 , se , qi , val);
	pre[si] = min(pre[2*si] , pre[2*si+1]);
	suff[si] = min(suff[2*si] , suff[2*si+1]);
}
 
int getMin(int si , int ss , int se , int qs , int qe , int st[]){
	if(ss > qe || se < qs) return INF;
	
	if(ss>=qs && se<=qe) return st[si];
	
	int mid = (ss + se) / 2;
	
	return min(getMin(2*si , ss , mid , qs , qe , st) ,
			   getMin(2*si+1 , mid+1 , se , qs , qe , st));
}
 
int main(){
	int n , q;
	int code , a , b;
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>ar[i];
	build(1 , 1 , n);
	
	while(q--){
		cin>>code;
		if(code == 1){
			cin>>a>>b;
			update(1 , 1 , n , a , b);
		}
		else{
			cin>>a;
			int L = getMin(1 , 1 , n , 1 , a , pre) + a;
			int R = getMin(1 , 1 , n , a , n , suff) - a;
			cout<<min(L , R)<<endl;
		}
	}
}
 
