#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;
	
	while(t--){
			
		int n, m, b=0, w=0;
		cin >> n >> m;
		
		char a[n][m];	
		memset(a, 'B', sizeof a);
		
		a[0][0] = 'W';
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) cout << a[i][j];
			cout << endl;
		}
		
	}

	

	return 0;
}
