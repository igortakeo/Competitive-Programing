#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

vector<int> prefix_function(string &s) {
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        int x;
        cin >> s >> x;
        n = s.size();
        vector<int> v = prefix_function(s);
         
        cout << n+(n-v[n-1])*(x-1)*1LL << '\n';
    }
    
    return 0;
}
