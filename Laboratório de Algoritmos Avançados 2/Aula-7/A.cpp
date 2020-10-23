#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define MAX 1001 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int dp[MAX][MAX];
string copy_s, s, ans;
int n, sz;

int solve(string c, int i){

    if(i == sz){
        int a = stoi(c);
        int r = a%n;
        if(r == 0 and ans.size() == 0){
            ans = copy_s;
            return 1;
        }
        return 0;
    }
    if(c.size() > 0 and dp[i][stoi(c)] != -1) return dp[i][stoi(c)];
    if(s[i] == '?'){
        int j = 0;
        if(i == 0) j = 1;
        while(j < 10){
           copy_s[i] = j + '0';
           c += copy_s[i];
           int a = stoi(c);
           int r = a%n;
           if(dp[i+1][r] == -1) dp[i+1][r] = solve(to_string(r), i+1);
           c.pop_back(); 
           j++; 
        } 
        copy_s[i] = '?';
    }
    if(s[i] != '?'){
        c += s[i];
        int a = stoi(c);
        int r = a%n;
        return dp[i+1][r] = solve(to_string(r), i+1);
    }
    
    return dp[i][(c.size() > 0) ? stoi(c) : 0] = 0;
}


int main(){
	fastcin	
    
    cin >> s;
    cin >> n;
   
    sz = s.size();    
    copy_s = s;
    memset(dp, -1, sizeof dp);
    solve("",0);	
    if(ans == "") cout << "*" << endl;
    else{
        cout << ans << endl;
    }   
	return 0;
}
	

