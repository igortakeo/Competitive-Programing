//
// Created by igortakeo on 16/06/19.
//
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, v[MAX], cnt=1;

int main(){

    cin >> n;
    for(int i=2; i<=n; i++){
        if(v[i] == 0) {
            v[i] = cnt;
            for(int j=i; j<=n; j+=i)v[j]=cnt;
             cnt++;
        }
    }

    for(int i=2; i<=n; i++) cout << v[i] << ' ';
    cout << endl;

    return 0;
}
