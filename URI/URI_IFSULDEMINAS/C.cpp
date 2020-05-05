#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int vis[s.size()];
		char c [5] = {'7', 'Q' , 'J', 'K', 'A'};
		
		memset(vis, 0, sizeof vis);
		
		vector<int>v;
		
		for(int i=0; i<s.size(); i++){
			if(s[i] == '7')v.push_back(i);
		}
		
		int ans = 0;
		for(auto a : v){
			int j = 0;
			
			for(int i = a; i<s.size(); i++){
				if(j == 5) break;
				
				if(s[i] == c[j] and vis[i] == 0){
					vis[i] = 1;
					j++;
				}
				
			}
			if(j == 5) ans++;
		}
		
		
		cout << s.size()-(ans*5) << endl;
	
		
	}
	

	return 0;
}
