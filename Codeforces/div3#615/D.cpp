#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

map<int, bool>m;
map<int, int>freq;

int main(){

	fastcin
		
	int q, x, y, ans=0;
	
	cin >> q >> x;
	
	for(int i=0; i<q; i++){
		cin >> y;
		int d = y%x;
		freq[d]++;
		m[d+x*(freq[d]-1)] = true;
		while(m[ans])ans++;
		cout << ans << endl;
	}		
	      
	return 0;
}
