#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>

using namespace std;

int main(){

	int n;
	cin >> n;
	bool v[n+1];
	int ans[n+1];
	vector<pii>d;
	set<int>s;

	memset(v, false, sizeof v);

	int x;
	for(int i = 1; i<=n; i++){
		cin >> x;
		ans[i] = x;
		if(x != 0) v[x] = true;
	}

	for(int i = 1; i<=n; i++){
		if(v[i] == false) s.insert(i);
	}	
	for(int i=1; i<=n; i++){
		if(ans[i] == 0){
			pii p;
			p.second = i;
			if(!v[i]) p.first = 0;
			else p.first = 1;
			d.pb(p);
		}
	}
	
	sort(d.begin(), d.end());
	int  m = s.size();
	int cnt = 0;
	for(int i=0; i<d.size(); i++){
		int v = d[i].second;
		auto it = s.begin();
		while(it != s.end()){
			if(m%2 != 0 and cnt < 3){
				cnt++;
				if((*it != v and ans[*it] != v) or (*it != v and s.size() == 1)) break;
			}
			else{
				if(*it != v) break;
			}
			it++;
		}
		ans[v] = *it;
		s.erase(*it);
	}

	for(int i=1; i<=n; i++) cout << ans[i] << ' ';
	cout << endl;
	
	return 0;
}