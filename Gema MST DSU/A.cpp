//
// Created by igortakeo on 06/06/19.
//
#include <bits/stdc++.h>
#define MAX 1001001
using namespace std;

struct edges{
    int x, y, z;
};

edges v[MAX];
int n, m, qlf[MAX], father[MAX];

bool compare(edges a, edges b){
    return a.z < b.z;
}
int find(int x){
    if(father[x] == x) return x;
    return father[x]= find(father[x]);
}
int join(int x, int y){
    father[y] = x;
}

int main(){
    int ans=0;
    cin >> n;
    for(int i=1; i<=n; i++){
        father[i] = i;
    }
    for(int i=1; i<= n; i++) cin >> qlf[i];
    cin >> m;
    int x, y, z;
    for(int i=0; i<m; i++){
        cin >> x >> y >> z;
        v[i].x = x;
        v[i].y = y;
        v[i].z = z;
    }

    sort(v, v+m, compare);
    for(int i=0; i<m; i++){
        int a = find(v[i].x);
        int b = find(v[i].y);
        if(a != b && b == v[i].y){
            join(a, b);
            ans += v[i].z;
        }
    }

    int cnt=0;
    for(int i=1; i<=n; i++){
        if(find(i) == i) cnt++;
        if(cnt > 1){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}