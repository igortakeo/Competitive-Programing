#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
    int n, k, m;
    cin >> n >> k >> m;

    int v[n];
    vector<int>r[m];

    for(int i=0; i<n; i++) cin >> v[i];

    for(int i=0; i<n; i++){
        r[v[i]%m].push_back(v[i]);
    }    
    
    for(int i=0; i<m; i++){
        if(r[i].size() >= k){
            cout << "Yes" << endl;
            for(int j=0; j<k; j++){
                cout << r[i][j] << ' ';
            }
            cout << endl;
            return;
        }
    }
    
    cout << "No" << endl;

}
int main(){
	fastcin	
	solve();
	return 0;
}
	

