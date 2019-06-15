#include <bits/stdc++.h>
#define ll long long
#define MAX 101
#define MOD 1000000007
using namespace std;
ll dp[MAX][MAX][MAX];

ll solve(ll x, ll y, ll z){
	if(x == 0 || y == 0 || z == 0) return 1;
	if(dp[x][y][z] != -1) return dp[x][y][z];
	ll ans=0;
	if(x >= y) ans+= solve(x-y, y, z);
	if(x >= z) ans+= solve(x-z, y, z); 
	if(y >= x) ans+= solve(x, y-x, z); 
	if(y >= z) ans+= solve(x, y-z, z);
	if(z >= x) ans+= solve(x, y, z-x);
	if(z >= y) ans+= solve(x, y, z-y);
	return dp[x][y][z] = ans%MOD;
}

int main(){
	ll a, b, c;
	memset(dp, -1, sizeof dp);	
	scanf("%lld %lld %lld",&a, &b, &c);	
	printf("%lld\n", solve(a,b,c));
	return 0;
}
