#include <bits/stdc++.h>
using namespace std;


int main(){

	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;


	vector<int>r(a), g(b), h(c);

	priority_queue<int>pq;


	for(int i=0; i<a; i++) cin >> r[i];

	for(int i=0; i<b; i++) cin >> g[i];

	for(int i=0; i<c; i++) cin >> h[i];
	

	sort(r.rbegin(), r.rend());	
	sort(g.rbegin(), g.rend());	
	sort(h.rbegin(), h.rend());
	

	for(int i=0; i<x; i++)pq.push(-r[i]);
	
	for(int i=0; i<y; i++)pq.push(-g[i]);

	
	for(int i=0; i<c; i++){
		int t = -pq.top();
		
		if(h[i] > t){
			pq.pop();
			pq.push(-h[i]);
		}

	}	


	long long ans = 0;

	while(!pq.empty()){
		ans += -pq.top();
		pq.pop();
	}



	cout << ans << endl;


	return 0;
} 

