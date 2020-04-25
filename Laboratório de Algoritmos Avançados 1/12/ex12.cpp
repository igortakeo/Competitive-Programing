#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		stack<int>v[n];	

		int j=1, x;

		while(true){
			bool flag = false;
			for(int i=0; i<n; i++){
				if(v[i].empty()){v[i].push(j); flag = true; break;}
				else{
					x = sqrt(v[i].top()+j);
					if(x*x == (v[i].top()+j)){v[i].push(j); flag = true; break;}
				}
			}

			if(!flag) break;
			j++;
		}

		cout << j-1 << endl;

	}


 return 0;
}
