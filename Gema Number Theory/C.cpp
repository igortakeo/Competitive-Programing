//
// Created by igortakeo on 29/06/19.
//
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main(){

    ll n;
    cin >> n;
    vector<ll>v;

    for(ll i=1; i*i<=n; i++){
        if(n%i == 0) {
            v.pb(i);
            if (i != (n / i)) v.pb(n/i);
        }
    }
    cout << v.size() << endl;
    return 0;
}
