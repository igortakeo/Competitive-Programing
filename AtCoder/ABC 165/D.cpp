#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	ll a, b, n;
	cin >> a >> b >> n;
	
	ll d = n/b;
	ll e = d*b-1;
	
	if(d == 0) cout << floor((a*n)/(double)b) - a*floor(n/(double)b) << endl;
	else cout << max(floor((a*e)/(double)b) - a*floor(e/(double)b), floor((a*n)/(double)b) - a*floor(n/(double)b)) << endl;
		 
	return 0;
}

