#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){

		int n, odd=0, even=0, sum=0;
		cin >> n;

		vector<int>v(n);

		for(int i=0; i<n; i++) cin >> v[i];

		for(int i=0; i<n; i++){
			sum += v[i];
			if(v[i]%2 == 0) even++;
			else odd++;
		}

		if(sum%2 != 0) cout << "YES" << endl;
		else{
			if((odd > 0 and even == 0) or(odd == 0 and even > 0)) cout << "NO" << endl;
			else cout << "YES" << endl;
		}


	}

	return 0;
}