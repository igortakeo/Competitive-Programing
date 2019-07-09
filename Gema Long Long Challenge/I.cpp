//
// Created by igortakeo on 08/07/19.
//
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){

    int n;
    cin >> n;
    deque<char>d(n);

    for(int i=0; i<n; i++) cin >> d[i];

    string ans;

    while(!d.empty()){
        if(d.front() < d.back()){
            ans+= d.front();
            d.pop_front();
        }
        else if(d.back() > d.front()){
            ans += d.back();
            d.pop_back();
        }
        else {
            int i = 0, j = d.size() - 1;
            while (d[i] == d[j] and i <= j) {
                i++;
                j--;
            }
            if (d[i] < d[j]) {
                ans += d.front();
                d.pop_front();
            } else {
                ans += d.back();
                d.pop_back();
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << ans[i];
        if(i%80 == 79) cout << endl;
    }
    cout << endl;

    return 0;
}



