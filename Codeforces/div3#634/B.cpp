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
		
		int n, a, b;
		cin >> n >> a >> b;
		
		char f[b];
		string ans= "";
		char c  = 'a';
		
		for(int i=0; i<b; i++){
			f[i] = c;
			c++;
		}		
		
		for(int i=0; i<n; i++) ans += f[i%b];
		
		cout << ans << endl;
		
		
	}


	return 0;
}
