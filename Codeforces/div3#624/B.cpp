#include <bits/stdc++.h>
#define MAX 110
#define pii pair<int, int>
using namespace std;


int main(){

	int t;
	cin >> t;

	while(t--){

		int n, m;
		cin >> n >> m;
		
		int a[n], p[m];

		for(int i=0; i<n; i++)  cin >> a[i];
		for(int i=0; i<m; i++)	cin >> p[i];

		
		set<int>s;	
		set<int>:: iterator it;

		for(int i=0; i<m; i++){
			s.insert(p[i]);
			s.insert(p[i]+1);
		}
		vector<pii>d;
		
		for(it = s.begin(); it != s.end(); it++){
			int v = *it, w = *it;
			it++;
			while(w+1 == *it and it != s.end()){
				w++;
				it++;
			}
			w = *it;
			d.push_back(pii(v, w));
			if(it == s.end()) break;
		}

		/*
		for(int i=0; i<d.size(); i++){
			cout << d[i].first << ' ' << d[i].second << endl;
		}
		*/

		for(int i=0; i<d.size(); i++){
			sort(a+d[i].first-1, a+d[i].second);
		}
		/*
		for(int i=0; i<n; i++) cout << a[i] << ' ';
		cout << endl;
		*/

		bool flag = false;	
		for(int i=0; i<n; i++){
			if(a[i] > a[i+1]){
				flag = true;
				break;
			}
		}	


		if(flag) cout << "NO" << endl;
		else cout << "YES" << endl;

	}


	return 0;
}