#include <bits/stdc++.h>
using namespace std;


map<long long, int>freq;	

int main(){
	
	int n;
	cin >> n;
	
	int v[n];
		
	for(int i=0; i<n; i++) cin >> v[i];
	
	int j, k;
	j = n/2 - 1;
	if(n%2 == 0){
		k = n/2;
	}
	else{
		k = n/2 + 1;
	}
	
	vector<int>PB, PM;
	
	
	for(int i=0; i<=j; i++){
		if(PB.size() == 0){
			PB.push_back(v[i]);
			continue;
		}
		PB.push_back(PB.back()+v[i]);
	}
	for(int i=n-1; i>=k; i--){
		if(PM.size() == 0){
			PM.push_back(v[i]);
			continue;
		}
		
		PM.push_back(PM.back()+v[i]);
	}

	for(int i=0; i<PB.size(); i++) freq[PB[i]]++;

	int ans = 0;
	for(int i=0; i< PM.size(); i++){
		if(freq[PM[i]] >= 1){
			ans = max(ans, PM[i]);
		}
	}
	
	
	cout << ans << endl;
	
	return 0;
}


