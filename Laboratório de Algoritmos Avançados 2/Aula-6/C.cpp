#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){
	fastcin	
	    
    ll n;
    string s;
    cin >> n;
    cin >> s;
    ll v[n];
    for(int i=0; i<n; i++) cin >> v[i];
    string hard = "hard";
    int j=0;
    for(int i=0; i<n; i++){
        if(j == 4) break;
        if(s[i] == hard[j]) j++;
    }

    if(j < 4){
        cout << 0 << endl;
        return 0;
    }

    string u ="", p ="";
    vector<ll>w, z;
    for(int i=0; i<n; i++){
        if(s[i] == 'h' or s[i] == 'a' or s[i] == 'r' or s[i] == 'd'){
            u += s[i];
            w.push_back(v[i]);
        }  
    }
    
    
    char c = u[0];
    p+=c;
    ll sum = w[0];
    for(int i=1; i<u.size(); i++){
        if(c == u[i]){
            sum += w[i];
        }
        else{
            z.push_back(sum);
            c = u[i];
            sum = w[i];
            p+=c;
        }
    }
    z.push_back(sum);
    
    int a[p.size()];
    ll dp[4], ans=0;
   
    memset(dp, 0, sizeof dp);

    for(int i=0; i<p.size(); i++){
        if(p[i] == 'h') a[i] = 0;
        else if(p[i] == 'a') a[i] = 1;
        else if(p[i] == 'r') a[i] = 2;
        else a[i] = 3; 
    }
  
    for(int i=0; i<p.size(); i++){
        if(a[i] == 0) dp[0] += z[i];
        else if(a[i] == 1) dp[1] = min(dp[0], dp[1]+z[i]);
        else if(a[i] == 2) dp[2] = min(dp[1], dp[2]+z[i]);
        else if(a[i] == 3) dp[3] = min(dp[2], dp[3]+z[i]);            
    }

    cout << dp[3] << endl;    

	return 0;
}
	

