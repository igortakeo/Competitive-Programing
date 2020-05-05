#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	int t;
	
	cin >> t;
	
	while(t--){
		
		string m[9];
		
		for(int i=0;i<9; i++) cin >> m[i];
		
		int j = 0;
		for(int i=0; i<9; i++){
			int v;
			v  = (m[i][j] - '0')%9+1;
			m[i][j] = v + '0';
			
			j = (j+4)%9;
		}
		
		
		
		for(int i=0;i<9; i++) cout << m[i] << endl;
		
	}
	
	
		
	return 0;
}
