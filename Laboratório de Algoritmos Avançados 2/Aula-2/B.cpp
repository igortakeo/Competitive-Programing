#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int a[30][30];
int n, m;

void solve(){	
    int ans=0;
    cin >> n >> m;
    int mt[n][m];
    map<int, pii>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> mt[i][j];
    }
    
    for(int i=0; i<n; i++){
        a[i][0] = i;
        for(int j=1; j<m; j++){
            a[i][j] = a[i][j-1]+1;
        }
    }
    
    int b = a[n-1][m-1], c=-1;
    if(b%2 == 0) c = b/2;
   
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x = a[i][j] - b;
            if(x < 0) x*=-1;
            if(x < a[i][j]) a[i][j] = x;
            
            if(c == a[i][j]) continue;

            if(mt[i][j] == 1) d[a[i][j]].first++;    
            else d[a[i][j]].second++;
        }
    }
    
    for(auto it : d){  
      ans += min(it.second.first, it.second.second);   
    }
 
    cout << ans << endl;

    memset(a, 0, sizeof a);

}
int main(){
	fastcin	
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
	

