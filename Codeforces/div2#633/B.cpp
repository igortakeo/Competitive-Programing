#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int v[n];
		
		for(int i=0; i<n; i++) cin >> v[i];
		
		sort(v, v+n);
			
		vector<int>ans;
		
		int i=0, j=n-1;
		
		while(i <= j){
			
			if(i == j)ans.push_back(v[i]);
			else{
				ans.push_back(v[j]);
				ans.push_back(v[i]);
			}
			j--;
			i++;
		}
		
		reverse(ans.begin(), ans.end());
		
		for(auto a : ans) cout << a << ' ';
		cout << endl;	
		
		
	}
	
	
	
	return 0;
}
