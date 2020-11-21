#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define inf 0x3f3f3f3f 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

map<string, pll>Dm;
ll nt;

ll solve(string s){	
    
    stack<string>St;
    ll sum = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ')'){
            string a, b;
            ll n, m, z;
            b = St.top();
            St.pop();
            a = St.top();
            St.pop();
            St.pop();
            
            if(Dm[a].second == Dm[b].first){n = Dm[a].first; m = Dm[b].second; z = Dm[a].second;}
            else return -1;

            sum += n*m*z;
            string p = "*";
            p += to_string(nt);
            nt++;   
            Dm[p].first = n;
            Dm[p].second = m;
            St.push(p);
        }
        else{
            string v = "";
            v += s[i];
            St.push(v);
        }
    }

    return sum;
}

int main(){
	fastcin	
    ll n;
    string s;
    cin >> n;
    while(n--){
        string c;
        ll x, y;
        cin >> c >> x >> y;
        Dm[c].first = x;
        Dm[c].second = y;
    }
    while(cin >> s){
        nt = 0;
        ll ans = solve(s);
        if(ans == -1) cout << "error" << endl;
        else cout << ans << endl;
    }

	return 0;
}

