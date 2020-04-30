#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

vector<int>pans;

void solve(vector<int>&v, int l, int r, int k){
	bool flag = true;
	int cnt = 0;
	int pos = 0;
	
	int mid  = (l+r)/2;

	while(v[pos] < (int)v.back()){
		
		int x = v[pos] + mid;
		
		int it = lower_bound(v.begin(), v.end(), x) - v.begin();
		if(v[it] > x or it == (int)v.size())it--;
		
		if(it == pos){
			flag = false;
			break;
		}
		else cnt++;
		
		pos = it;
	}	
	
	if(flag and cnt-1 <= k) pans.push_back(mid);
	
	if(l > r or mid == l or mid == r) return;
	
	if(cnt-1 <= k and flag) solve(v, l, mid, k);
	else solve(v, mid+1, r, k);
}

int main(){
	
	int n, k;
	
	while(scanf("%d %d", &n, &k) != EOF){
		int x;
		
		vector<int>v(n+2);
		v[0] = 0;
		
		for(int i=1; i<=n+1; i++){
			cin >> x;
			v[i] = v[i-1]+x;	 
		}

		solve(v, 0, v[n+1], k);
		int ans = *min_element(pans.begin(), pans.end());		
		
		cout << ans << endl;
		
		pans.clear();
	}
	
	
	return 0;
}
