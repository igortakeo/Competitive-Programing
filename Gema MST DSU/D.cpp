//
// Created by igortakeo on 07/06/19.
//
#include <bits/stdc++.h>
#define MAX 1001001
#define pb push_back
using namespace std;

int pai[MAX], qtd[MAX];

int find(int x){
    if(pai[x] == x) return x;
    return find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(qtd[x] >= qtd[y]){
        pai[y]=x;
        qtd[x]+= qtd[y];
    }
    else{
        pai[x] = y;
        qtd[y]+= qtd[x];
    }

}

int main(){

    int n, m, a, b;
    vector<int>v;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        pai[i] = i;
        qtd[i] = 1;
    }

    for(int i=0; i<m; i++){
        cin >> a;
        for(int k=0; k<a; k++){
            cin >> b;
            v.pb(b);
        }
        for(int j=1; j<a; j++) join(v.front(), v[j]);
        v.clear();
    }

    for(int i=1; i<=n; i++) cout << qtd[find(i)] << ' ';
    cout << endl;

    return 0;
}