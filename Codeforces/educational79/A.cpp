#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){

		int v[3];

		for(int i=0; i<3; i++) cin >> v[i];

		sort(v, v+3);

		if(v[2] > v[0] + v[1] + 1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}

	return 0;
}