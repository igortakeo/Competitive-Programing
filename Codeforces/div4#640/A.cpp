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
		string n;		
		cin >> n;
		
		vector<int>ans;
		reverse(n.begin(), n.end());
		
		for(int i=n.size()-1; i>=0; i--){
			if(n[i] == '0') continue;
			int d = (n[i] - '0')*(pow(10, i));
			ans.push_back(d);	
		}
		cout << ans.size() << endl;
		for(auto a : ans) cout << a << ' ';
		cout << endl;
	}	
	
	      
	return 0;
}
	
