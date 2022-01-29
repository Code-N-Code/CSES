//video solution link : https://www.youtube.com/watch?v=LC4I9xaEW_Q&list=PL2q4fbVm1Ik7RiRG7KnHjxmblwFEGfVdR&index=6

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct Node{
	ll prefix;
	ll sum;
};
 
const int N = 2e5;
Node st[4*N];
int ar[N+1];
 
void mergeResult(int si){
	st[si].sum = st[2*si].sum + st[2*si+1].sum;
	st[si].prefix = max(st[2*si].prefix , st[2*si].sum + st[2*si+1].prefix);
}
 
void build(int si , int ss , int se){
	if(ss == se){
		st[si].prefix = st[si].sum = ar[ss];
		return;
	}
	
	int mid = (ss + se) / 2;
	build(2*si     , ss    , mid);
	build(2*si + 1 , mid+1 , se);
	mergeResult(si);
}
 
void update(int si , int ss , int se , int qi , int val){
	if(qi < ss || qi > se) return;
	
	if(ss == se && ss == qi){
		st[si].sum = st[si].prefix = ar[ss] = val;
		return;
	}
	
	int mid = (ss + se) / 2;
	update(2*si , ss , mid , qi , val);
	update(2*si+1 , mid+1 , se , qi , val);
	mergeResult(si);
}
 
Node maxProfit(int si , int ss , int se , int L ,int R){
	if(ss > R || se < L){
		Node temp;
		temp.prefix = temp.sum = 0;
		return temp;
	}
	
	if(ss >= L && se <= R) return st[si];
	
	int mid = (ss + se) / 2;
	Node l = maxProfit(2*si , ss , mid , L , R);
	Node r = maxProfit(2*si + 1 , mid + 1 , se , L , R);
	Node res;
	res.sum = l.sum + r.sum;
	res.prefix = max(l.prefix , l.sum + r.prefix);
	return res;
}
 
int main(){
	int n , q , k , u , a , b;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++) cin>>ar[i];
	build(1 , 1 , n);
	
	while(q--){
		int code;
		cin>>code;
		if(code == 1){
			cin>>k>>u;
			update(1 , 1 , n , k , u);
		}
		else{
			cin>>a>>b;
			cout<<max(0LL , maxProfit(1 , 1 , n , a , b).prefix)<<endl;
		}
	}
}
 
