#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
    map<char, double>dic;
    
    double amount = 0, dollar = 0, cents = 0;
    ll n, m;
    cin >> n;

    while(n--){
        char c;
        ll v;
        cin >> c >> v;
        dic[c] = v;
    }
    
    cin >> m;
    cin.ignore();
    while(m--){
        string s;
        getline(cin ,s);
        
        for(int i=0; i<(int)s.size(); i++) amount += dic[s[i]]/100;
    }
    
    printf("%.2lf$\n", amount);
}
int main(){
	fastcin	
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
	

