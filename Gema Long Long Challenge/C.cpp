//
// Created by igortakeo on 06/07/19.
//
#include <bits/stdc++.h>
using namespace std;
int main(){

    int n, cnt=0;
    cin >> n;
    string s;
    cin >> s;

    for(int i=1; i<n-1; i++){
        if(s[i] == s[i-1]){
            if(s[i] == 'R'){
                if(s[i+1] == 'G')s[i] ='B';
                else s[i] = 'G';
            }
            else if(s[i] == 'B'){
                if(s[i+1] == 'R') s[i] = 'G';
                else s[i] = 'R';
            }
            else if(s[i] == 'G'){
                if(s[i+1] == 'B') s[i] = 'R';
                else s[i] = 'B';
            }
            cnt++;
        }
    }

    if(s[n-1] == s[n-2]){
        if(s[n-1] == 'R') s[n-1] ='B';
        else if(s[n-1] == 'G') s[n-1] ='B';
        else s[n-1] = 'G';
        cnt++;
    }

    cout << cnt << endl;
    cout << s << endl;
    return 0;
}
