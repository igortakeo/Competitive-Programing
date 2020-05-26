#include <iostream>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX (int)1e6+5
using namespace std;

void solve(){

	int n, k, ones = 0;
	string s;
			
	cin >> n >> k;
	cin >> s;
			
	for(int i=0; i<n; i++){
		if(s[i] == '1') ones++;
	}	
	
	int ans = ones;
	
	for(int j=0; j<k; j++){
		int cnt = 0;
		for(int i=j; i<n; i+=k){
			if(s[i] == '1')	cnt++;	
			else cnt--;
			if(cnt < 0) cnt = 0;
			ans = min(ans, ones-cnt);
		}
		
	}	
	
	cout << ans << endl;

}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
