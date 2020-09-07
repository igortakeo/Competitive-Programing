#include <bits/stdc++.h>
#define ll long long
#define pb push_back 
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
    ll n, k;
    cin >> n >> k;

    vector<ll>a,b,c;

    for(int i=0; i<n; i++){
        ll t, x, y;
        cin >> t >> x >> y;
        
        if(x == 0 and y == 0) continue;

        if(x == 1 and y == 1)a.pb(t);
        else if(x == 0 and y == 1) b.pb(t);
        else c.pb(t);
    }
   
    ll time = 0;
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    
    for(int i=0; i<min(c.size(), b.size()); i++) a.pb(b[i]+c[i]);
    
    sort(a.begin(), a.end());

    if(a.size() < k){
        cout << -1 << endl;          
        return;
    }
    
    int cnt = 0;
    for(int i=0; i<k; i++){;
        time+=a[i];
    }

    cout << time << endl;
    
}
int main(){
	fastcin	
	solve();
	return 0;
}
	

