#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int test;

void solve(){	
    int n;
    cin >> n;
    set<int>v[n];
    int p[n];
    int freq[10001];
    memset(freq, -1, sizeof freq);
    
    for(int j = 0; j < n; j++){ 
        int u, x;
        cin >> u;        
        for(int i=0; i<u; i++){
            cin >> x;
            v[j].insert(x);
        }
        for(auto a : v[j]){
            freq[a]++;
        }
    }
    
    for(int j=0; j<n; j++){
        int cnt = 0;
        for(auto a : v[j]){
            if(freq[a] == 0) cnt++;
        }
        p[j] = cnt;
    }
    
    int total = 0;
    for(int i=0; i<n; i++) total += p[i];
    cout << "Case " << test << ":";
    for(int i=0; i<n; i++){
        double ans = (p[i]*100.0)/(double)total;
        cout << fixed;
        cout << setprecision(6) << ' ' <<  ans << "%";
    }
    
}
int main(){
	fastcin	
	int t;
    test = 1;
	cin >> t;
	while(t--){
        solve();
        cout << endl;
        test++;
    }
	return 0;
}
	

