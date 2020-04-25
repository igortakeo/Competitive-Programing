#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#define pb push_back
#define pf pop_front

using namespace std;

map<int, int>team;

int main(){

	int n, cnt = 1;
	deque<queue<int>>q;
	string s;
	cin >> n;

	while(n != 0){
		int m, x;

		for(int i=1; i<=n; i++){
			cin >> m;
			for(int j=0; j<m; j++){
				cin >> x;
				team[x] = i;
			}
		}

		cin >> s;
		vector<int>ans;

		while(s != "STOP"){

			if(s == "ENQUEUE"){
				cin >> x;
				bool flag = false;
				for(int i=0; i<(int)q.size(); i++){
					if(team[q[i].front()] == team[x]){
						flag = true;
						q[i].push(x);
					}
				}
				if(!flag){
					queue<int> d;	
					d.push(x);
					q.pb(d);
				}	

			}
			else{
				ans.pb(q[0].front());
				q[0].pop();
				if(q[0].empty())q.pf();
			}
			cin >> s;
		}

		cout << "Scenario #" << cnt << endl;
		for(auto a : ans) cout << a << endl;	
		cout << endl;

		cnt++;
		cin >> n;
		q.clear();
	}


	return 0;
}