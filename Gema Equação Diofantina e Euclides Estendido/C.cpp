#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
    int n, x, m;
    cin >> n >> x;
    int v[n];
    for(int i=0; i<n; i++) cin >> v[i];
    m = v[0];
    for(int i=1; i<n; i++){
        m = __gcd(m, v[i]);
    }

    if(x%m == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

}
int main(){
	fastcin	
	solve();
	return 0;
}
	

