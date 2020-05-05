#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	
	while(n != 0){
		
		int a[2*n];
		
		vector<int>v;
		
		for(int i=0; i<2*n; i++) cin >> a[i];
		
		int j=0, k=2*n-1;
		
		while(j<n){
			v.push_back(a[j]+a[k]);
			j++; k--;
		}
		
		sort(v.begin(), v.end());
		
		cout << v[n-1] << ' ' <<v[0] << endl;
		
		cin >> n;
	}
	
	

	return 0;
}
