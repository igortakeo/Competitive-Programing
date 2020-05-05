#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){

		int n;
		string s;
		map<pii, int>m;
		vector<pair<int, pii>>v;

		cin >> n;
		cin >> s;

		pii u = {0,0};

		for(int i=0; i<n; i++){

			if(m[u] != 0) v.push_back({(i+1)-m[u], {m[u], i}});

			m[u] = i+1;
			
			if(s[i] == 'L') u.second -= 1;
			else if(s[i] == 'R') u.second += 1;
			else if(s[i] == 'D') u.first += 1;
			else if(s[i] == 'U') u.first -= 1;

		}


		if(m[u] != 0) v.push_back({n-m[u], {m[u], n}});

		sort(v.begin(), v.end());

		if(v.size() == 0) cout << -1 << endl;
		else cout << v[0].second.first << ' ' << v[0].second.second << endl;


	}



	return 0;
}