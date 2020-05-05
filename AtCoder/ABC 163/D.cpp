#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MOD (ll)(1e9+7)
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
		
	ll n, k, ans = 0;
	cin >> n >> k;
	
	ll sum[n+1];
	
	memset(sum, 0, sizeof sum);
	
	for(int i=1; i<=n; i++) sum[i] += sum[i-1] + i;
	
	/*
	 * Example : n = 5, k = 3
	 * 
	 * 0 1 2 3 4 5
	 *
	 * for k = 3
	 * 
	 * Possible Combinations:
	 * (0,1,2) = 3
	 * (0,1,3) = 4
	 * (0,1,4) = 5
	 * (0,1,5) = 6
	 * (0,2,5) = 7
	 * (0,3,5) = 8
	 * (0,4,5) = 9
	 * (1,4,5) = 10
	 * (2,4,5) = 11
	 * (3,4,5) = 12
	 * 
	 * Possible Sums: 3,4,5,6,7,8,9,10,11,12
	 * 
	 * Always sums will have difference equal one,
	 * starting of lesser possible sum until bigger 
	 * possible sum
	 * 
	 * We need to know how many numbers have in between
	 * the bigger and lesser number. 
	 *
	 * Therefore : (12 - 3) + 1 = 10 
	 * 
	 * Do repeat of k until n+1
	 * 
	 * 
	 */ 
	
	for(int i=k; i<=n+1; i++){
		
		ll s = sum[i-1];
		ll x = sum[n], y;
		
		(i == n+1) ? y = 0 : y = sum[n-i];
		
		ll b = x-y;
		
		ans += (b-s+1)%MOD;
	}
	
	cout << ans%MOD << endl;
	
	
	return 0;
}
