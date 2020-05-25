#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int freq[15][26];

void solve(){	
	int n, m;
	cin >> n >> m;
	
	vector<string>v;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		v.push_back(s);
	}
	
	string ans;
	
	for(int j=0; j<m; j++){		
		ans = v[0];
		for(int i=0; i<26; i++){
			ans[j] = 'a'+i;
			int d = 0;
			for(int k = 1; k<v.size(); k++){
				string b = v[k];
				int cnt = 0;
				for(int l=0; l<m; l++){
					if(ans[l] != b[l]) cnt++;
				}
				d = max(d, cnt);
			}		
			if(d <= 1){
				cout << ans << endl;
				return;
			}
		}
	}
	
	cout << -1 << endl;
	
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
