//
// Created by igortakeo on 06/07/19.
//
#include <bits/stdc++.h>
using namespace std;
int main(){

    string s, p;
    cin >> s >> p;
    int cnt_1=0, cnt_2=0, cnt_3=0, cnt_4=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '#' and p[i] == '#') cnt_1++;
        else if(s[i] == '#' and p[i] == '.') cnt_2++;
        else if(s[i] == '.' and p[i] == '#') cnt_3++;
        else if(s[i] == '.' and p[i] == '.') cnt_4++;
    }

    if(cnt_1 == 0){
        if(cnt_2 > 0 and cnt_3 > 0){
            cout << "NO" << endl;
            return 0;
        }
    }

    string ans_1, ans_2;

    while(cnt_1 > 0 or cnt_2 > 0 or cnt_3 > 0 or cnt_4 > 0) {
        if(cnt_2>0){ans_1+='#';ans_2+='.';cnt_2--;}
        else if(cnt_1>0){ans_1+='#'; ans_2+='#'; cnt_1--;}
        else if(cnt_3>0){ans_1+='.'; ans_2+='#'; cnt_3--;}
        else if(cnt_4>0){ans_1+='.'; ans_2+='.'; cnt_4--;}
    }

    cout << "YES" << endl;
    cout << ans_1 << endl;
    cout << ans_2 << endl;

    return 0;
}
;