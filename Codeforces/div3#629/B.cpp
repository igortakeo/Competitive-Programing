#include <bits/stdc++.h>

using namespace std;

int main(){


	int t;
	cin >> t;

	while(t--){

		int n, k;
		cin >> n >> k;

		char s[n];
		int v = 1;
		int cnt = 1, aux=1;
		if(k > 1){
			v = v + cnt;
			while(k >= v){
				cnt++;
				v = v + cnt; 	
			}
			v -= cnt;			
		}
		
		int u = (n-1)-cnt, w = (n-(k-v))-1;
		if(k == 1){u=n-2; v=n-1;}


		s[u] = 'b';
		s[w] = 'b';

		for(int i=0; i<n; i++){
			if(i == u or i == w) continue;
			s[i] = 'a';
		}

		for(int i=0; i<n; i++) cout << s[i];
		cout << endl;

	}


	return 0;
}
