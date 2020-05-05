#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;

	cin >> t;

	while(t--){

		int n;
		cin >> n;

		if(n < 10) cout << n << endl;
		else{
			int x, y, ans = 0;
			while(n >= 10){
				x = n%10;
				y = n/10;
				ans += n - x;
				n = n-(n-x);
				n+=y;
			}
			ans += n;
			cout << ans << endl;
		}


	}



	return 0;
}