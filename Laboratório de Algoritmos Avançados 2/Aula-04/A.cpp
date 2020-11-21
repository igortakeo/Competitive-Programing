#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

char s[22][22];
int vis[22][22];
int u[22][22];
vector<pii>mov;
set<string>c[402];
int n, lim;

void solve(int i, int j, string t){	
    t+=s[i][j];
    if(t.size() >= 3 and t.size() <= lim){
         c[t.size()].insert(t);
    }
    if(t.size() == lim) return; 
       
    if(t.size() == 1) u[i][j] = 1;

    vis[i][j] = 1;
    
    for(auto a : mov){
        if(vis[i+a.first][j+a.second]) continue;
        if(i+a.first < 0 or i+a.first == n or j+a.second < 0 or j+a.second == n) continue;
        
        if(s[i+a.first][j+a.second] > t.back())
            solve(i+a.first, j+a.second, t);   
    }
    
    t.pop_back();
    vis[i][j] = 0;
    
    if(t.size() == 0){
        for(auto a : mov){
            if(u[i+a.first][j+a.second]) continue;
            if(i+a.first < 0 or i+a.first == n or j+a.second < 0 or j+a.second == n) continue;
            solve(i+a.first, j+a.second, t);   
        }
    }
     

}
int main(){
	fastcin	
	     
    mov.push_back(make_pair(-1,0));
    mov.push_back(make_pair(1,0));
    mov.push_back(make_pair(-1,-1));
    mov.push_back(make_pair(-1,1));
    mov.push_back(make_pair(0,-1));
    mov.push_back(make_pair(0,1));
    mov.push_back(make_pair(1,-1));  
    mov.push_back(make_pair(1,1));
  
    int t;
    bool flag = false;
	cin >> t;
	
    while(t--){
        cin.ignore();

        cin >> n;
        
        lim = n*n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> s[i][j];
            }
        }

        string p = "";
        solve(0, 0, p);
        int cnt = 0;
        
        for(int i=3; i<=400; i++){
            for(auto a : c[i]) {
                cout << a << endl;
            }
        }
        
        if(t) cout << endl;        

        for(int i=0; i<=400; i++) c[i].clear();
        memset(u, 0, sizeof u); 
        memset(vis, 0, sizeof vis);
    }

	return 0;
}
	

