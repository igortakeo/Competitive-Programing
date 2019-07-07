//
// Created by igortakeo on 06/07/19.
//
#include <bits/stdc++.h>

using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    long long l = pow(10,m);
    cout<<(n*l)/__gcd(n,l) << endl;
    return 0;
}
