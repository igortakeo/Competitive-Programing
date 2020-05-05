#include <bits/stdc++.h>

using namespace std;

int main(){


	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;

		vector<int>d;
		
		d.push_back(0);
		for(int i=0; i<s.size(); i++){
			if(s[i] == 'R') d.push_back(i+1);
		}
		d.push_back(s.size()+1);

		int ans = 0, diff;
		for(int i=1; i<d.size(); i++){
			diff = d[i] - d[i-1];
			ans = max(diff, ans);
		}

		cout << ans << endl;

	}


	return 0;
}