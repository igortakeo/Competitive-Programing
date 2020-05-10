#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll pw[32];
map<int, int>m;

void solve(){
	int n, pos, ans=0, aux;
	ll mx, mm;
	cin >> n;
	vector<ll>v(n);
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	bool flag = true;
	for(int i=0; i<n-1; i++){
		if(v[i] > v[i+1]){
			flag = false;
			break;
		}
	}
	
	if(flag){
		cout << 0 << endl;
		return;
	}
	
	aux = v[0];
	m[v[0]] = aux;
	for(int i=1; i<n; i++){
		if(v[i] < aux) m[v[i]] = aux;
		else{
			aux = v[i];
			m[v[i]] = aux;
		}
	}
	
	sort(v.begin(), v.end());

	int diff, mdiff=0;
	for(int i=0; i<n; i++){
		int diff = m[v[i]] - v[i];
		if(m[v[i]] > v[i] and diff > mdiff){
			mm = v[i];
			mx = m[v[i]];
			mdiff = diff;
		}
	}
	
	for(int i=0; i<=31; i++){
		mm += pw[i];
		ans++;
		if(mm >= mx) break;	
	}

	
	cout << ans << endl;
	m.clear();
}

int main(){

	fastcin
	
	for(int i=0; i<=31; i++) pw[i] = pow(2,i); 
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
