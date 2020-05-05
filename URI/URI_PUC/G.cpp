#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n, m, s;
	cin >> n >> m >> s;
	
	int mt[n][m];
	
	memset(mt, 0, sizeof mt); 
	
	int x, y, z;
	for(int i=0; i<s; i++){
		cin >> x >> y >> z;
		mt[x][y] = z;
	}
	
	int first = 0, second = 0;
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cout << mt[i][j] << ' ';
		cout << endl;
	}
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if((i > 0 and j > 0) and (i> 0 and j<m-1) and (i< n-1 and j< m-1))first+=mt[i][j];
			else second += mt[i][j];
		}
	}


	
	cout << first <<' ' << second<< endl;
		
	return 0;
}
