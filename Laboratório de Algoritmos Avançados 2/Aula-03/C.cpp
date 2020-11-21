#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

char m[150][150];
int aux[150][150];
int r, c;
string s = "ALLIZZWELL";
bool flagANS;
vector<pii>mov;
set<int>path;

void solve(int i, int j, int pos){	   
    path.insert(aux[i][j]);
    
    if(pos == 10){
        flagANS = true;;
        return;
    }

    for(auto a : mov){
                
        if(i+a.first < 0 or i+a.first == r or j+a.second < 0 or j+a.second == c) continue;

        if(m[i+a.first][j+a.second] == s[pos] and path.find(aux[i+a.first][j+a.second]) == path.end()){
            solve(i+a.first, j+a.second, pos+1);
        }
             
    }
 
    path.erase(aux[i][j]);
}
int main(){
	fastcin	
    int cnt = 1;
    
    mov.push_back(make_pair(-1,0));
    mov.push_back(make_pair(1,0));
    mov.push_back(make_pair(-1,-1));
    mov.push_back(make_pair(-1,1));
    mov.push_back(make_pair(0,-1));
    mov.push_back(make_pair(0,1));
    mov.push_back(make_pair(1,-1));  
    mov.push_back(make_pair(1,1));
    
    for(int i=0; i<150; i++){
        for(int j=0; j<150; j++){
            aux[i][j] = cnt;
            cnt++;
        }
    }


	int t;
	cin >> t;
	while(t--){
        cin >> r >> c;    
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> m[i][j];
            }
        }
        cin.ignore();
        flagANS = false;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(m[i][j] == 'A')solve(i,j,1);
                if(flagANS) break;
            }
        }
                
        if(flagANS) cout << "YES" << endl;
        else cout << "NO" << endl;

        memset(m, 0, sizeof m);
        path.clear();
    }
	return 0;
}
	

