#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	int n, m, a, b;
	cin >> n >> m;
	
	int h[n+1];
	int ans[n+1];
	
	for(int i=1;i<=n; i++) ans[i] = 1;
	
	for(int i=1; i<=n; i++) cin >> h[i];
	
	for(int i=0; i<m; i++){
		cin >> a >> b;	
		if(h[a] > h[b]) ans[b] = 0;
		else if(h[a] < h[b]) ans[a] = 0;
		else{ans[a]=0; ans[b]=0;}
	}
	
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(ans[i]) cnt++;
	}
	
	cout << cnt << endl;
	      
	return 0;
}

