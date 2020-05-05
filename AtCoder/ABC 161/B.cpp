#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n,m;
	cin >> n >> m;
	
	int v[n], sum = 0;
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	for(int i=0; i<n; i++) sum+=v[i];
	
	int d = ceil(sum/(4.0*m));
	
	bool flag = true;
	
	sort(v, v+n);
	reverse(v, v+n);

	for(int i=0; i<m; i++){
		if(v[i] < d){flag = false; break;}
	}
	
	if(flag) cout << "Yes" << endl; 
	else cout << "No" << endl; 
	
	return 0;
}
