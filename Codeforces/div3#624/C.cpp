#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n, m;
		cin >> n >> m;
		
		string s, a = "", b="";
		int p[m], freq[26], ans[26];
		
		memset(freq, 0, sizeof freq);
		memset(ans, 0, sizeof ans);
			
		cin >> s;
		for(int i=0; i<m; i++) cin >> p[i];
		
		sort(p, p+m);
		
		int j=0;
		for(int i=0; i<m; i++){
			while(j < p[i]){freq[s[j]-'a']++;j++;}
			
			for(int k=0; k<26; k++) ans[k]+=freq[k];
		}
		
		
		for(int i=0; i<n; i++) ans[s[i]-'a']++;
		
		for(int i=0; i<26; i++) cout << ans[i] << ' ';
		cout<< endl;	
		
	}
	
	
	
	      
	return 0;
}
