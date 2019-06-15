//
// Created by igortakeo on 14/06/19.
//
#include <bits/stdc++.h>
#define MAX 150003
using namespace std;

int n, pai[MAX];
vector<int>ans[MAX];

int find(int x){
    if(pai[x] == x) return x;
    return find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(ans[x].size() >= ans[y].size()){
        pai[y]=x;
        for(int i=0; i<ans[y].size(); i++)ans[x].push_back(ans[y][i]);
        ans[y].clear();
    }
    else{
        pai[x] = y;
        for(int i=0; i < ans[x].size(); i++)ans[y].push_back(ans[x][i]);
        ans[x].clear();
    }

}

int main(){
    int x, y, degree=0;
    cin >> n;

    for(int i=1; i<=n; i++){
        ans[i].push_back(i);
        pai[i]=i;
    }

    for(int i=0; i<n-1; i++){
        cin >> x >> y;
        join(x, y);
    }

    for(int i=1; i<=n; i++){
        if(pai[i] == i){
            degree =i;
            break;
        }
    }
    for(int i=0; i<ans[degree].size();i++)cout << ans[degree][i] << ' ';
    cout << endl;
    return 0;
}