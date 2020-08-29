#include <bits/stdc++.h>
#define Max 1001001
using namespace std;

int ans, a[Max];

int solve(string &s, int i, int j, int ant){

    if(ant < min(a[i], a[j])){
        ant = min(a[i], a[j]);
        if(a[i] == a[j]){
            int sz = s.size();
            int di = solve(s, i+1, j, ant);
            int dj = solve(s, i, j-1, ant);
            s.erase(s.begin()+sz, s.end());
            if(di >= dj){s+= 'L';return 1+solve(s, i+1, j, ant);}
            else{s+= 'R';return 1+solve(s, i, j-1, ant);}
        }
        if(ant == a[i]){s+='L'; return 1+solve(s, i+1, j, ant);}
        if(ant == a[j]){s+='R'; return 1+solve(s, i, j-1, ant);}
    }
    else if(ant < max(a[i], a[j])){
        ant = max(a[i], a[j]);
        if(ant == a[i]){s+='L'; return 1+solve(s, i+1, j, ant);}
        if(ant == a[j]){s+='R'; return 1+solve(s, i, j-1, ant);}
    }

    return 0;

}

int main(){

    int  n;
    cin >> n;
    string s;

    for(int i=0; i<n; i++) cin >> a[i];

    int i=0, j=n-1;
    ans = solve(s, i, j, -1);

    cout << ans << endl;
    cout << s << endl;

    return 0;
}
