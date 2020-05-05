#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, a, b, k;
	cin >> n >> a >> b >> k;

	vector<int>v(n), u;
	int ans = 0;

	for(int i=0; i<n; i++) cin >> v[i];


	int d = a+b;

	
	for(int i=0; i<n; i++){

		if(v[i]%d == 0){
			int y = v[i]/d;
			int z = v[i]-(y*a+(y-1)*b);
			u.push_back(ceil(z/(float)a));
		}
		else{
			int w = v[i]%d;
			int p = ceil(w/(float)a);
			u.push_back(p-1);
		}
	}


	sort(u.begin(), u.end());


	for(int i=0; i<u.size(); i++){
		if(k >= u[i]){k-=u[i]; ans++;}
		else break;
	}

	cout << ans << endl;



	return 0;
}