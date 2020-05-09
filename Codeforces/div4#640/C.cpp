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
		int n, k, i;
		cin >> n >> k;
		
		int f = k/(n-1);
		int d = f*(n-1);
		int a = n*f;
		
		if(k == d) cout << a-1 << endl;
		else cout << (k-d)+a << endl;
		
	}	
	
	      
	return 0;
}
	
