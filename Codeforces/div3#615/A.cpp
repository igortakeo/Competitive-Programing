#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		int v[3];
		int n;
		
		for(int i=0; i<3; i++) cin >> v[i];
		
		cin >> n;
		
		sort(v, v+3);
		
		int g = v[2] - v[1];
		int h = v[2] - v[0];
		int d = g+h;
		v[1]+=g;
		v[0]+=h;
		n-= d;
		
		if(n%3 == 0 and v[0] == v[1] and v[1] == v[2] and n >= 0) cout << "YES" << endl;
		else cout << "NO" << endl;			

	}
		
	
	
	return 0;
}
