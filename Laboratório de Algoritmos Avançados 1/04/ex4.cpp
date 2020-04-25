#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){

	int n;

	cin >> n;

	while(n != 0){

		int ans = 0, t = 1;
		map<int, int>m;

		for(int j=0; j<n; j++){
			int x;

			int v[5];

			for(int i=0; i<5; i++){
				cin >> x;
				v[i] = x;
			}

			sort(v, v+5);

			int sum = 0;
			for(int k = 1; k<=5; k++) sum += 2*v[k-1]*k;
			m[sum]++;

			if(t < m[sum]){
				t = m[sum];
				ans = m[sum];	
			} 
			else if(t == m[sum]) ans += m[sum]; 
		}

		cout << ans << endl;

		
		cin >> n;
	}

	return 0;
}
