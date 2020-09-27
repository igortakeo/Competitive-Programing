#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


string solve(string s){
    int n = s.size();
    if(n%2 != 0) return s;
    string s1 = solve(s.substr(0, n/2));
    string s2 = solve(s.substr(n/2, n/2));
    return min(s1+s2, s2+s1);
}


int main(){
	fastcin	
	string s,p;
    cin >> s >> p;
    int n = s.size();

    if(s == p){
        cout << "YES" << endl;
        return 0;
    }

    if(n%2 != 0 and s == p){
        cout << "YES" << endl;
        return 0;
    }
    else if(n%2 != 0){
        cout << "NO" << endl;
        return 0;
    }

    s = solve(s), p = solve(p);

    if(s == p) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
	

