#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

string bg, ed;
unordered_map<string, bool>vis;
unordered_map<string, int>dist;

void bfs(string x){
	
	queue<string>q;
	q.push(x); 

	string v,s;
	
	char c;
	int w;

	while(!q.empty()){
				
		v = q.front(); 
		q.pop();

		if(v == ed) return; 	 

		vis[v] = true;

		for(int i=0; i < 4; i++){
			s = v;
			c  = s[i];
			w = ((int)c-'0'+1)%10; 
			s[i] = w + '0';
			if(!vis[s]){
				dist[s] = dist[v] + 1;
				vis[s] = true;
				q.push(s);
			}
		}
		
		for(int i=0; i < 4; i++){
			s = v;
			c  = s[i];
			w = ((int)c-'0'-1)%10;
			if(w == -1) w = 9;
			s[i] = w + '0';
			if(!vis[s]){
				dist[s] = dist[v] + 1;
				vis[s] = true;
				q.push(s);
			}
		}
	
	}

}

int main(){

	int n, t;
	char x;
	cin >> n;


	while(n--){

		for(int i=0; i<4; i++){
			cin >> x;
			bg+=x;
		}

		for(int i=0; i<4; i++){
			cin >> x;
			ed+=x;
		}

		cin >> t;
		string s;

		for(int i=0; i<t; i++){
			for(int i=0; i<4; i++){
				cin >> x;
				s+=x;
			}
			vis[s] = true;
			s.clear();
		}

		bfs(bg);

		if(dist[ed] == 0 and bg != ed) cout << -1 << endl;
		else cout << dist[ed] << endl;

		vis.clear();
		bg.clear();
		ed.clear();
		dist.clear();
	}


	return 0;
}
