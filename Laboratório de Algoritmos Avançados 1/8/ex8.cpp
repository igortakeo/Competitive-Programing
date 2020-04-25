#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <utility>
#define ll long long
#define pii pair<int, int>

using namespace std;
map<int, ll> id;

int main(){


	int n, m, k, u, v, ans=0;
	ll x;
	
	cin >> n >> m >> k;

	priority_queue<pii> pq;
	vector<int>box[n+1];

	for(int i=1; i <= n; i++){
		cin >> x;
		id[i] = x;
	}

	for(int i=1; i<=n; i++){
		cin >> u;
		for(int j=0; j<u; j++){
			cin >> v;
			box[i].push_back(v);
		}
	}

	for(int i=0; i<m; i++){
		cin >> u;
		pq.push(pii(id[u], u));
	}

	for(int i=0; i<k; i++){
		int w = pq.top().second;
		pq.pop();
		if((int)box[w].size() == 0) ans++;
		else{
			for(int j=0; j<(int)box[w].size(); j++)pq.push(pii(id[box[w][j]],box[w][j]));
		}
	}

	cout << ans << endl;


	return 0;
}