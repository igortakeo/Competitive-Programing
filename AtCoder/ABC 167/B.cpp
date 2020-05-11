#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	
	int k, ans=0;
	int v[3] = {1,0,-1};
	int t[3];
	
	for(int i=0; i<3; i++) cin >> t[i];
	cin >> k;
	
	for(int i=0; i<3; i++){
		if(k >= t[i]){
			k-=t[i];
			ans += v[i]*t[i];
		}
		else{
			ans += v[i]*k;
			break;
		}
	}
	
	cout << ans << endl;

}

int main(){

	fastcin
	
	solve();
	      
	return 0;
}
	

