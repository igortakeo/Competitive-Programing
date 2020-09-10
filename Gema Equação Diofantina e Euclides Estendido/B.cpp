#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int n;

void solve(){	
    int a, b, c;
    cin >> a >> b >> c;
    
    if(c%__gcd(a,b) == 0)
        printf("Case %d: Yes\n", n);
    else
        printf("Case %d: No\n", n);   

}

int main(){
	fastcin	
	int t;
	cin >> t;
    n = 1;
	while(t--){
        solve();
        n++;
    }
	return 0;
}
	

