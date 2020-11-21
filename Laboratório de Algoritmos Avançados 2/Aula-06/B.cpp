#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Max 100100
#define ll long long
#define pb push_back
#define ps push
#define ppk pop_back
#define pp pop
#define sz size
#define ey empty
#define it insert
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pii pair<int, int>
using namespace std;
 
int main(){
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<int>v(n);
	
	for(int i=0; i<n; i++)cin >> v[i];
	
	map<int, int>dp;
	
	int ans=0, lst=0;
	for(int i=0; i<n; i++){
		dp[v[i]] = dp[v[i]-1]+1;
		if(ans < dp[v[i]]){
			ans=dp[v[i]];
			lst=v[i];
		}
	}
	
	vector<int>rst;
	
	for(int i=n-1;i>=0;i--){
		if(lst == v[i]){
			rst.pb(i+1);
			lst--;
		}
	}
	
	reverse(rst.begin(), rst.end());
	
	cout << ans << endl;
	for(auto a:rst)
		cout << a << ' ';
	cout << '\n';	
		
	return 0;
}
