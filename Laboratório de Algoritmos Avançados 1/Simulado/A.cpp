#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		int n, l, r;
		cin >> n;

		queue<pii>q;

		for(int i=1; i<=n; i++){
			cin >> l >> r;
			q.push({r,l});
		}

		int cnt = 1;
		while(!q.empty()){
			pii a = q.front();
			q.pop(); 
			if(a.first >= cnt){
				cnt = max(a.second, cnt);
				cout << cnt << ' ';
				cnt++;
			}
			else{
				cout << 0 << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}