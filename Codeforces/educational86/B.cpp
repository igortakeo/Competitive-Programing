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
		string s;
		
		cin >> s;
		
		queue<int>q;
		char c = s[0];
		
		for(int i=1; i<s.size(); i++){
			if(c == s[i])q.push(i);	
		}
		q.push(s.size());
		
		int k;
		while(!q.empty()){
			k = q.front();
			bool flag = true;
			q.pop();
			
			int j=1;
			while(j+k < s.size()){
				if(s[j] != s[j+k]){
					flag = false;
					break;
				}
				j++;
			}
			
			if(flag)break;
			
		}
		
		if(k <= 2) cout << s << endl;
		else{
			string ans="";
			int cnt=2*s.size();
			char a = '1';
			while(cnt--){
				ans+=a;
				if(a == '1') a='0';
				else a='1';
			}
			
			cout << ans << endl;
			
		}	
	}	
	      
	return 0;
}
