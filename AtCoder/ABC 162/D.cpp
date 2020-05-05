#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	
	int n;
	ll ans=0;
	
	vector<int>R, G, B;
	
	string s;
	
	cin >> n;
	cin >> s;
	
	for(int i=0; i<n; i++){
		if(s[i] == 'R')R.push_back(i);
		else if(s[i] == 'G')G.push_back(i);
		else if(s[i] == 'B')B.push_back(i);
	}
	
	
	for(int i=0; i<R.size(); i++){
		for(int j=0; j<G.size(); j++){
			int diff = G[j]-R[i];
			int a = G[j] + diff;
			
			ans += lower_bound(B.begin(), B.end(), a) - B.begin();
			ans += B.size() - (upper_bound(B.begin(), B.end(), a) - B.begin());		
		}
	}
	
	
	cout << ans << endl;

	return 0;
}
