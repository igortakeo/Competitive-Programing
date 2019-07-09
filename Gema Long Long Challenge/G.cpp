//
// Created by igortakeo on 08/07/19.
//
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    string s;
    cin >> s;

    string m[6] = {"RGB", "RBG", "BGR", "BRG", "GBR", "GRB"};

    for(int i=0; i<6; i++){
        vector<char>v, u;
        for(int j=0; j<s.size(); j++){
            if(s[j] == m[i][0]) v.pb(s[j]);
            else if(s[j] == m[i][2])u.pb(s[j]);
            else{
                if(u.size() == 0)u.pb(s[j]);
                else if(u.back() == s[j]) u.pb(s[j]);
                else v.pb(s[j]);
            }
        }
        int cnt=0;
        bool flag = false;
        for (int k = 1; k < v.size(); k++) {
            if (v[k] != v[k - 1]) cnt++;
            if (cnt > 1) {
                flag = true;
                break;
            }
        }

        if(!flag){
            cout << "YES" << endl;
            return 0;
        }

    }

    cout << "NO" << endl;

    return 0;
}