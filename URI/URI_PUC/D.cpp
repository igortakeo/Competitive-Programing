#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n, s;
	
	while(scanf("%d%d", &n, &s) != EOF){
			
		int m[n][n];
		memset(m, 0, sizeof m);
		
		int d = (n-1)/2;
		int cnt = 3;
		
		m[d][d] = 1;
		
		if(n == 1) cout << 0 << ' ' << 0 << endl;
		else{
			m[d][d+1] = 2;
			
			for(int i=0; i<3; i++){
				m[d+1][d+1-i] = cnt;
				cnt++;
			}

			for(int i=1; i<3; i++){
				m[d+1-i][d-1] = cnt;
				cnt++;
			}
			
			for(int i=1; i<3; i++){
				m[d-1][d-1+i] = cnt;
				cnt++;
			}
			
			int v=2;
			int j = d-1;
			int k = d+2;
			
			while(j!= 0 and k != n){	
				while(j<n and j <= d+v ){
					m[j][k] = cnt; 
					cnt++;
					j++;
				}
				j--;k--;
				while(k>=0 and k >=d-v){
					m[j][k] = cnt; 
					cnt++;
					k--;
				}
				k++;j--;
				while(j >= 0 and j >= d-v){
					m[j][k] = cnt; 
					cnt++;
					j--;
				}
				j++;k++;	
				while(k < n and k <= d+v){
					m[j][k] = cnt; 
					cnt++;
					k++;
				}		
			
				v++;
			}
			
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(m[i][j] == s){cout << i << ' ' << j << endl; break;}
				}
			}
		}
		
	}
	

	return 0;
}
