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
		int n, k;
		cin >> n >> k;
		
		set<string>c1;
		
		string s;
		cin >> s;
		
		sort(s.begin(), s.end());
		
		if(k == 1) cout << s << endl;
		else{
			string v[k], a, b;
			int j = 0;
			
			for(int i=0; i<s.size(); i++){
				v[j] += s[i];
				j = (j+1)%k;
			}
				
			for(int i=0; i<k; i++) c1.insert(v[i]);
			
			if(s[0] != s[k-1])a = s[k-1];
			else a = s.substr(k-1, n-(k-1));	
			
			auto it  = c1.end();
			it--;
			b = *it;	
			
			if(lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())){
					cout << a << endl;
			}
			else cout << b << endl;
			
		}	
		
	}
		
	      
	return 0;
}

