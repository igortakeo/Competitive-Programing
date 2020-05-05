#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin

	int t;
	
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		if(n == 1 or n == 2) cout << 0 << endl;
		else{
			if(n%2 == 0) cout << n/2-1 << endl;
			else cout << n/2 << endl;
			
		}
		
	}

	return 0;
}
