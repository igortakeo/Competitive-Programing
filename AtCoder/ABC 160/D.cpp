#include <bits/stdc++.h>
#define N 2005
using namespace std;

vector<int>vertices[N]; 
int vis[N], dist[N]; 
map<int, int>m;

void bfs(int x){
	
	queue<int>fila;
	fila.push(x); 
	vis[x] = 1;  
	dist[x] = 0;	

	int v  = 0, u  = 0;
	while(!fila.empty()){
			
		v = fila.front(); 
		fila.pop();  
		
		for(int i=0; i < vertices[v].size(); i++){
			u = vertices[v][i];
			if(vis[u] == 0){ 
				dist[u] = dist[v] + 1;
				fila.push(u);
				vis[u] = 1;
			}
		}
	}

}


int main(){

	int n, x, y;
	cin >> n >> x >> y;

	for(int i=2; i <= n; i++){
		vertices[i-1].push_back(i);
		vertices[i].push_back(i-1);
	}

	vertices[x].push_back(y);
	vertices[y].push_back(x);

	for(int i=1; i<n; i++){
		memset(vis, 0, sizeof vis);
		memset(dist, 0, sizeof dist);
		bfs(i);
			
		for(int j=i; j<=n; j++) m[dist[j]]++;

	}

	
	for(int i=1; i<n; i++) cout << m[i] << endl;

	return 0;
}