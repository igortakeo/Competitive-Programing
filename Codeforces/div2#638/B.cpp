#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 10000
using namespace std;

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int v[n], cnt = 0;
		int freq[n+1];
		
		memset(freq, 0, sizeof freq);
		
		for(int i=0; i<n; i++) cin >> v[i];
		
		for(int i=0; i<n; i++){
			if(freq[v[i]] == 0) cnt++;
			freq[v[i]]++;
		}
		
		if(n == k){
			cout << n << endl;
			for(int i=0; i<n; i++) cout << v[i] << ' ';
			cout << endl;
		}
		else if(cnt > k) cout << -1 << endl;
		else{
			vector<int>ans, a;
			
			int i = 0;
			while(a.size() < k){
				if(freq[i] > 0){
					a.push_back(i);
					freq[i]--;
				}	
				i++;
				i%=(n+1);	
			}
			
			int j = 0;
			while(ans.size() < MAX){
				ans.push_back(a[j]);
				j++;
				j%=k;
			}
			
			cout << ans.size() << endl;
			for(auto it : ans) cout << it << ' ';
			cout << endl;
			
		}
		
	}
		

	return 0;
}
