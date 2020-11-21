#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
    int n;
    cin >> n;
    int v[2*n];
    int p[100];
    vector<int>ans;
    memset(p, 0, sizeof p);
    for(int i=0; i<2*n; i++) cin >> v[i];
    for(int i=0; i<2*n; i++){
        if(p[v[i]] == 0){
            ans.push_back(v[i]);
            p[v[i]] = 1;
        }
    }
    for(auto a : ans) cout << a << ' ';
    cout << endl;
}
int main(){
	fastcin	
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
	

