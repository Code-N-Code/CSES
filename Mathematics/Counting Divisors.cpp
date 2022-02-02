#include<bits/stdc++.h>

using namespace std;

const int N = 1000000;
int divSum[N+1];

void preproccess(){

	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j+=i)
		divSum[j]++;
	}
}

int main(){

	int n , m;
	cin>>n;
	preproccess();
	while(n--) cin>>m , cout<<divSum[m]<<endl;

}
