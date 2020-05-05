#include <bits/stdc++.h>
#define MAX 200005
#define MAXLEVEL 20
using namespace std;

vector<int> tree[MAX];
int depth[MAX];
int parent[MAX][MAXLEVEL];
int dist[MAX];

void dfs(int v, int prev, int d){
	
	depth[v] = depth[prev] + 1;
	parent[v][0] = prev;
	dist[v] = d;
	 
	for(int i=0; i<tree[v].size(); i++){
		int u = tree[v][i];	
		if(u != prev) dfs(u, v, d+1);
	}
	
}

void precomputeSM(int n){
		
	for(int i=1; i<=ceil(log2(n)); i++){
		for(int j=1; j<=n; j++){
			if(parent[j][i-1] != -1){
				parent[j][i] = parent[parent[j][i-1]][i-1];	
			}
		}
	}
	
}

int lca(int v, int u, int n){
	
	if(depth[v] < depth[u]) swap(u,v);		
	
	int diff = depth[v] - depth[u];
	
	for(int i=0; i<=ceil(log2(n)); i++){
		if((diff >> i)&1) v = parent[v][i];
	}
	
	for(int i=ceil(log2(n)); i>=0; i--){
		if(parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}	
	}
	
	return parent[u][0];
}

int main(){
	
	memset(parent, -1, sizeof parent);
	
	int n, m, x, y;
	cin >> n >> m;
	
	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	dfs(1, 0, 0);
	precomputeSM(n);
	
	while (m--){
		int k;
		cin >> k;
		
		int a[k];
		
		for(int i=0; i<k; i++) cin >> a[i];
		
		int mdepth=0, aux=-1;
		for(int i=0; i<k; i++){
			if(dist[a[i]] > aux){
				aux = dist[a[i]];
				mdepth = a[i];
			}	
		}
		
		bool flag = true;
		for(int i=0; i<k; i++){
			if(a[i] == mdepth) continue;	
			int u = lca(mdepth, a[i], n);
			
			if(dist[a[i]] - dist[u] > 1){flag = false; break;}	
			
		}
		
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
 
	}

	return 0;
}

