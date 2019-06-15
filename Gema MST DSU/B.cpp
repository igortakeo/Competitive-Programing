//
// Created by igortakeo on 07/06/19.
//
#include <bits/stdc++.h>
#define MAX 123
using namespace std;
int pai[MAX], qtd[MAX], vis[MAX];
set<int>cj;

int find(int x){
    if(pai[x] == x) return x;
    return find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    if(qtd[x] >= qtd[y]){
        pai[y] = x;
        qtd[x] += qtd[y];
    }
    else{
        pai[x]=y;
        qtd[y] += qtd[x];
    }

}

int main(){
    int n;
    string s, p;
    cin >> n;
    cin >> s >> p;

    for(int i=1; i<MAX; i++){
        pai[i] = i;
        qtd[i] = 1;
    }

    for(int i=0; i<n; i++){
        join((int)s[i], (int)p[i]);
        cj.insert((int)s[i]);
        cj.insert((int)p[i]);
    }
    int total = 0;
    for(auto it : cj){
        int a = find(it);
        if(vis[a] == 0) total+= qtd[a]-1;
        vis[a] = 1;
    }

    cout << total << endl;

    for(auto it : cj){
        int b = find(it);
        if(b == it) continue;
        cout << (char)it << ' ' << (char)b << endl;
    }

    return 0;
}