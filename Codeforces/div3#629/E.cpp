#include <bits/stdc++.h>
#define N 200001

using namespace std;

vector<int> edges[N], querie[N], depth[N]; 
bool vis[N];
int degree[N], f[N], ans[N];

void dfs(int x, int dg, int p){
	
	vis[x] = true;
	degree[x] = dg;
	f[x] = p;

	for(int i = 0; i < edges[x].size(); i++){  
		int u = edges[x][i]; 
		if(!vis[u]) dfs(u,dg+1,x);
	}

}

void dfs__(int x, set<int>&path){
	vis[x] = true;
	path.insert(x);

	for(auto a : depth[x]){
		bool flag = true;
		for(auto b : querie[a]){
			if(path.find(b) == path.end() and path.find(f[b]) == path.end()){flag = false; break;}
		}	
		if(flag) ans[a] = 1;
	}


	for(int i=0; i<edges[x].size(); i++){
		int u = edges[x][i];
		if(!vis[u])dfs__(u, path);
	}

	path.erase(x);
}



int main(){

	int n, m, cnt=0;
	cin >> n >> m;

	int x, y;
	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	dfs(1,0,1);

	while(m--){
		int k, x;
		cin >> k;

		for(int i = 0; i<k; i++){
			cin >> x;
			querie[cnt].push_back(x);
		}

		int mdegree=0, aux=-1;
		for(int i=0; i<k; i++){
			if(degree[querie[cnt][i]] > aux){
				aux = degree[querie[cnt][i]];
				mdegree = querie[cnt][i];
			}	
		}

		depth[mdegree].push_back(cnt);

		cnt++;
	}

	set<int>path;
	memset(vis, false, sizeof vis);
	dfs__(1,path);


	for(int i=0; i<cnt; i++){
		if(ans[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	return 0;
}