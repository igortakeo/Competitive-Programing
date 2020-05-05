#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int main(){
	
	int n, ans = MAX;
	
	int c[3] = {-1, 0, 1};

	cin >> n;
		
	vector<int>a(n), b(n);
	
	for(int i=0; i<n; i++) cin >> b[i];
	
	
	for(int i=0; i<3; i++){
		a[0] = b[0] + c[i]; 
		for(int j=0; j<3; j++){
			a[1] = b[1] + c[j];
			int diff = a[1] - a[0];
			int cnt = abs(a[0]-b[0]) + abs(a[1]-b[1]); 
			bool flag = true;
			for(int k=2; k<n; k++){
				a[k] = a[k-1] + diff;
				if(abs(a[k]-b[k]) == 1) cnt++;
				else if(abs(a[k]-b[k]) > 1){
					flag = false;
					break;
				}
			}
			if(flag) ans = min(cnt, ans);
		}
	
	}
	
	
	if(ans == MAX) cout << -1 << endl;
	else cout << ans << endl;

	
	return 0;
}
