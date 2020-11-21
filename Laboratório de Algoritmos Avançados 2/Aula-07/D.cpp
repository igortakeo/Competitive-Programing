#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int lis(vector<int>&v){	

    int n = v.size();
    vector<int>arr_lis(n, 1);

	for(int i=1; i<n; i++){
		for(int j=0; j < i; j++){
			if(v[i] > v[j]) arr_lis[i] = max(arr_lis[i], arr_lis[j]+1);
		}
	}

	return *max_element(arr_lis.begin(), arr_lis.end());
}
int main(){
	fastcin	
	int t, cnt=1;
	cin >> t;

	while(t != -1){
        if(cnt > 1) cout << endl;

        vector<int>v;
        v.push_back(t);

        while(true){
            cin >> t;
            if(t == -1)break;
            v.push_back(t);
        }
        
        for(int i=0; i<v.size(); i++) v[i]*=-1;

        int ans = lis(v);

        cout << "Test #" << cnt << ":" << endl;
        cout << "  " << "maximum possible interceptions: " << ans << endl; 
        
        cin >> t;
        cnt++;
    }

	return 0;
}
	

