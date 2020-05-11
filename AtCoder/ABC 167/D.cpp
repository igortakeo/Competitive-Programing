#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX 20000005
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll vis[MAX], cycle[MAX];
map<ll, ll>ttime;
map<ll, ll>inverstime;

void solve(){
	ll n, k;
	cin >> n >> k;
	
	ll v[n+1];
	
	for(int i=1; i<=n; i++) cin >> v[i];
	
	ll j=1, t=0;
	while(vis[j] == 0){
		ttime[t] = j;
		inverstime[j] = t;
		vis[j] = 1;
		j = v[j];
		t++;
	}	
	
	if(k < t){
		cout << ttime[k] << endl;
		return;		
	}
	
	ll init = j, d = t-inverstime[j];
	cycle[0] = init;
	j = v[init];
	
	for(int i=1;;i++){
		if(j == init) break;
		cycle[i] = j;
		j = v[j];
	}
	
	k -= t-d;
		
	cout << cycle[k%d] << endl;
}

int main(){

	fastcin
	solve();      
	return 0;
}
	

