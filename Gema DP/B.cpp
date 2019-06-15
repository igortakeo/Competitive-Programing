#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
string s, p;
int dp[MAX][MAX];

int lcs(int x, int y){
	
	if(dp[x][y] != -1) return dp[x][y];
	if(x == 0 or y == 0) return 0;
	if(s[x-1] == p[y-1]) return lcs(x-1, y-1)+1;
	return dp[x][y] = max(lcs(x, y-1), lcs(x-1, y));
}

int main(){
	memset(dp, -1, sizeof dp);	
	cin >> s >> p;
	printf("%d\n", lcs(s.size(), p.size()));
	
	return 0;
}
