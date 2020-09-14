#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

string s;

int solve(int l, int r, char c){	
    int sz = (l+r)/2;
   
    if(l == sz){
        return (s[l] == c) ? 0 : 1; 
    }

    string a,b;
    int Na=0, Nb=0;
    a = s.substr(l, r-sz);
    b = s.substr(sz, r-sz);

    for(int i=0; i<a.size(); i++){
        if(a[i] != c) Na++;
    }

    for(int i=0; i<b.size(); i++){
        if(b[i] != c) Nb++;
    }

    return min(Na+solve(sz, r, c+1), Nb+solve(l, sz, c+1));    
}

int main(){
	fastcin
	int t;
    cin >> t;
	while(t--){
        int n;
        cin >> n;
        cin >> s;        
        int ans = solve(0, n, 'a');
        cout << ans << endl;
    }
	return 0;
}
	

