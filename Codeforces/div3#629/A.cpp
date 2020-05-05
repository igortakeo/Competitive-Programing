#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;


	while(t--){

		int a, b;
		cin >> a >> b;

		int d = a/b;

		if(a%b == 0) cout << 0 << endl;
		else cout << (d+1)*b-a << endl;

	}


	return 0;
}