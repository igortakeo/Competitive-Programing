//
// Created by igortakeo on 06/07/19.
//
#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
int freq[MAX];

int main(){

    int n, ans=0;
    cin >> n;
    vector<int>v(n);

    for(int i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        int u = v[i];
        for(int j = n-1; j > i; j--)ans = max(++freq[u+v[j]], ans);
    }

    cout << ans << endl;

    return 0;
}
