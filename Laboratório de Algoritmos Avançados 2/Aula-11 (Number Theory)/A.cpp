#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define inf 0x3f3f3f3f
#define MAXN 16000000 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
int spf[MAXN], f[MAXN];
 
void sieve() { 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) spf[i] = i;  
    for (int i=4; i<MAXN; i+=2)spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++){  
        if (spf[i] == i) {  
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) spf[j] = i; 
        } 
    } 
}
 
int main(){
	fastcin	
	sieve();
    int n, gcd, ans=-1;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    gcd = v[0];
    for(int i=1;i<n; i++) gcd = __gcd(gcd, v[i]);
    for(int i=0; i<n; i++){
        int z = v[i]/gcd;
        int u = z;
        while(u > 1){
            f[spf[u]]++;
            int x = spf[u];
            while(u%x == 0)u/=x;
        } 
    }    
    for(int i=2; i<MAXN; i++){
        ans = max(ans, f[i]);
    }

    if(ans > 0) cout << n-ans << endl;
    else cout << -1 << endl;  
    
	return 0;
}
