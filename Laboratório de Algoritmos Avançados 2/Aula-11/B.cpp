#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define inf 0x3f3f3f3f 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
map<int, int>f;
int main(){
	fastcin	
	int n, cnt;
    cin >> n;
    int v[n*n], ans[n];
    cnt = n;
    set<int>s;
    for(int i=0; i<n*n; i++) cin >> v[i];
    for(int i=0; i<n*n; i++) f[v[i]]++;
    for(int i=0; i<n*n; i++) s.insert(-v[i]);
    for(auto a : s){
        a*=-1;
        while(f[a] > 0){
            ans[--cnt] = a;
            f[a]--;
            for(int j = cnt+1; j<n; j++) f[__gcd(a, ans[j])]-=2; 
        }
        
    }
    
    for(int i=0; i<n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    
	return 0;

}

