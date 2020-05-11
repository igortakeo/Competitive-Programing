#include <iostream>
#include <string.h>
#define MAXN 2000
#define MAXG 200
#define MAXW 50
using namespace std;

int price[MAXN], weight[MAXN], family[MAXG];
int dp[MAXN][MAXW];
int n, g, ans_;

int s(int i, int current_weight){
	
	if(i > n or current_weight == 0) return 0;
	
	if(dp[i][current_weight] > 0) return dp[i][current_weight];
	 
	int r1=0, r2=0;
	
	if(weight[i] <= current_weight) r1 = s(i+1, current_weight-weight[i])+price[i];
	
	r2 = s(i+1, current_weight);
	
	return dp[i][current_weight] += max(r1, r2);
}


void solve(){
	int ans=0;
	cin >> n;
	
	for(int i=1; i<=n; i++) cin >> price[i] >> weight[i];

	cin >> g;
	for(int i=1; i<=g; i++)cin >> family[i];
	
	
	for(int i=1; i<=g; i++) ans += s(1, family[i]);
	
	cout << ans << endl;
	
	memset(dp, 0, sizeof dp);
	memset(weight, 0, sizeof weight);	
	memset(price, 0, sizeof price);	
	memset(family, 0, sizeof family);	
	ans_=0;
}	


int main(){
	
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      	
	return 0;
}
