//
// Created by igortakeo on 06/07/19.
//
#include <bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    if(n <= 2){
        cout << "No" << endl;
        return 0;
    }

    vector<int> v, t;
    bool flag = false;
    for(int i=1; i<=n; i++){
        if(!flag) v.push_back(i);
        else t.push_back(i);
        flag = !flag;
    }


    cout << "Yes" << endl;
    cout << v.size() << ' ';
    for(auto a : v) cout << a << ' ';
    cout << endl;
    cout << t.size() << ' ';
    for(auto a : t) cout << a << ' ';
    cout << endl;


    return 0;
}