#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	int n, k;
	cin >> n >> k;
	
	int f[n+1];
	
	memset(f, 0, sizeof f);
	
	while(k--){
		int d, x;
		cin >> d;
		for(int i=0; i<d; i++){
			cin >> x;
			f[x] = 1;
		}
	}
	
	int ans = 0;
	
	for(int i=1; i<=n; i++){
		if(f[i] == 0) ans++;
	}
	
	cout << ans << endl;
	      
	return 0;
}
