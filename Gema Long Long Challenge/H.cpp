//
// Created by igortakeo on 08/07/19.
//
#include <bits/stdc++.h>
using namespace std;
int main(){

    int n;
    int a[10];
    bool flag = false;
    string s;
    cin >> n;
    cin >> s;

    for(int i=1; i<=9; i++)cin >> a[i];

    for(int i=0; i<n; i++){
        int u = s[i]-'0';
        if(u < a[u] or (flag and u <= a[u])) {
            s[i] = a[u]+'0';
            flag = true;
        }
        else if(flag == true)break;
    }

    cout << s << endl;


    return 0;
}
