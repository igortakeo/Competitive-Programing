#include <bits/stdc++.h>
#define MAX 1001001
using namespace std;
int n, dp[MAX][32], v[MAX];
int solve(int x, int ant){
	if(x > n) return 0;
	if(dp[x][ant] != -1) return dp[x][ant];
	if(v[x] == 0) dp[x][ant] = MAX;	
	if(v[x] == 2) dp[x][ant] = min(solve(x+1, ant)+1 , solve(x+(ant*2)+1, ant*2)+1);	
	if(v[x] == 1) dp[x][ant] = solve(x+1, ant)+1;
	return dp[x][ant]; 	
}

int main(){
	cin >> n;	
	string s;
	cin >> s;
	memset(dp, -1, sizeof dp);
	for(int i=1; i<=s.size(); i++){
		if(s[i-1]=='p') v[i]=2;
		else if(s[i-1] == 'x') v[i]=1;
		else v[i]=0;
	}
	int ret = solve(1,1);
	if(ret >= MAX) ret = -1;
	printf("%d\n", ret);
	return 0;
}
