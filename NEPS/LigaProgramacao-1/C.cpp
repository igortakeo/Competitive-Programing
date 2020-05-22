#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	vector<int>v(n);
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	sort(v.rbegin(), v.rend());
	
	for(int i=0; i<n-2; i++){
		int a = v[i], b = v[i+1], c = v[i+2];
		if(a+b > c and a+c > b and c+b > a){
			vector<int>s;
			s.push_back(a);
			s.push_back(b);
			s.push_back(c);
			sort(s.begin(), s.end());
			for(auto it : s) cout << it << ' ';
			cout << endl;
			
			return;
		}
	}
}

int main(){

	fastcin
	solve();      
	return 0;
}
	
