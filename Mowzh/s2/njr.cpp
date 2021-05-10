#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	
	cin>>n;
	int p[n];
	int dp[n+1];
	dp[0]=0;
	for(int i=1 ; i<=n;i++){
		cin>>p[i];
	}
	for (int i=1;i<=n;i++){
		int q = -1e9;
		for(int j=1;j<=i;j++){
			q  = max(q,p[j]+dp[i-j]);
			
		}
		dp[i]=q;
	}
	cout<<dp[n];
}