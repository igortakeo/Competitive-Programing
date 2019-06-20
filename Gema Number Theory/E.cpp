//
// Created by igortakeo on 19/06/19.
//
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
typedef long long ll;
int freq[MAX];
set<ll>s;

void crivo(){
    for(ll i=2; i< MAX; i++){
        if(freq[i] == 0) {
            s.insert(i);
            for (ll j = i*i; j < MAX; j=j+i) freq[j] = 1;

        }
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    ll x;
    cin >> n;
    crivo();

    while(n--){
        cin >> x;
        ll y = sqrt(x);
        if(y*y == x){
            if(s.count(y)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout <<"NO"<< endl;

    }
    return 0;
}