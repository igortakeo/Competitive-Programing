//
// Created by igortakeo on 29/06/19.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    
    ll n, m;
    cin >> n >> m;
    ll x = pow(10,m);
    cout << (x*n)/__gcd(x,n) << endl;
    return 0;
}