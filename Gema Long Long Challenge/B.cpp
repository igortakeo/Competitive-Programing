//
// Created by igortakeo on 06/07/19.
//
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    char m[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> m[i][j];
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j] == '.' and (i-1 >=0 and i+1<n and j-1 >=0 and j+1<n)){
                if(m[i-1][j] == '.' and m[i+1][j] == '.' and m[i][j+1] =='.' and m[i][j-1] =='.'){
                    m[i][j] = '#';
                    m[i-1][j] = '#';
                    m[i+1][j] = '#';
                    m[i][j-1] = '#';
                    m[i][j+1] = '#';
                }

            }

        }
    }


    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j] == '.'){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
