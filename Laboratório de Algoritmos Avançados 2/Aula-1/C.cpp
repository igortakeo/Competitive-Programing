#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
    int l, m, ans=0, p=1;
    cin >> l >> m;
    l*=100;
    deque<int>lef, rig;

    for(int i= 0; i<m; i++){
        int x;
        string s;
        cin >> x >> s;
        if(s == "left") lef.push_back(x);
        else rig.push_back(x);
    }
    
    while(!lef.empty() or !rig.empty()){
        if(p == 1){
            int acc = 0;
            while(acc + lef.front() <= l and !lef.empty()){
                acc += lef.front();
                lef.pop_front();
            }
            ans++;
            p = 2;
        }
        else{
            int acc = 0;
            while(acc + rig.front() <= l and !rig.empty()){
                acc += rig.front();
                rig.pop_front();
            }
            ans++;
            p = 1;
        }
    }

    cout << ans << endl;
   
}
int main(){
	fastcin	
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
	

