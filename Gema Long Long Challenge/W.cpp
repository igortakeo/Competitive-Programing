#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){

    long long t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        vector<long long>v;
        vector<long long>ans;
        for(int i=0; i<n; i++){cin >> x; v.pb(x);}
        sort(v.begin(), v.end());
        long long mmc = v.back()*v.front();
        for(long long i=2; i*i <= mmc; i++){
            if(mmc%i == 0){
                ans.pb(i);
                if(i != mmc/i)ans.pb(mmc/i);
            }
        }
        sort(ans.begin(), ans.end());
        if(v == ans) cout << mmc << endl;
        else cout << -1 << endl;

    }
    return 0;
}