#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define ppb pop_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


struct node{
	int a, b, c, d;
};

int n, m, q, ans;
vector<int>v;
vector<node>Q;

void solve(int i, int j){
	if(i == n){
		int cnt = 0;
		
		for(auto it : Q){
			if(v[it.b-1] - v[it.a-1] == it.c) cnt += it.d;
		}
		
		ans = max(ans, cnt);
		return;
	}
	
	for(int k=j; k<=m; k++){
		v.pb(k);
		solve(i+1, k);
		v.ppb();
	}
}

int main(){

	fastcin
	
	cin >> n >> m >> q;
	
	for(int i=0; i<q; i++){
		struct node n;
		cin >> n.a >> n.b >> n.c >> n.d;
		Q.push_back(n);
	}	
	
	solve(0, 1);		
	 
	cout << ans << endl; 
	      
	return 0;
}
