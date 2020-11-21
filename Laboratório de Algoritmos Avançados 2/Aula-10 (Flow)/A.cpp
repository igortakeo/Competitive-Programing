#include <bits/stdc++.h>
#define MAX 110
#define inf 0x3f3f3f3f
using namespace std;

int graph[MAX][MAX];
int rgraph[MAX][MAX];
int path[MAX*MAX];


bool bfs(int n, int s, int t){
	
	bool vis[n+1];
	memset(vis, false, sizeof vis);
	
	queue<int>q;
	vis[s] = true;
	q.push(s);
	
	
	while(!q.empty()){
		
		int u = q.front();
		q.pop();
		
		for(int i=1; i<=n; i++){
			if(!vis[i] and rgraph[u][i] > 0){
				q.push(i);	
				path[i] = u;
				vis[i] = true;
			}
		}	
		
		
	}
	
	return vis[t];
}


int FordFulkerson(int n, int s, int t){
		
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) rgraph[i][j] = graph[i][j];
	
	int maxflow = 0;
		
	while(bfs(n, s, t)){
		
		int pathflow = inf;
		
		
		//Find minimum residual capacity.
		for(int i=t; i!=s; i=path[i]){
			int j = path[i];
			pathflow = min(pathflow, rgraph[j][i]);
		}	
		
		//Update residual capacities and reverse edges.
		for(int i=t; i!=s; i=path[i]){
			int j = path[i];
			rgraph[j][i] -= pathflow;
			rgraph[i][j] += pathflow;
		}
		
		maxflow += pathflow;	
		memset(path, 0, sizeof path);
	}

	return maxflow;
}


int main(){

    int nt = 1;
    int n;
    cin >> n;

    while(n != 0){

	    int m, s, t;
	    cin >> s >> t >> m;
	
	    int u, v, w;   
	    for(int i=0; i<m; i++){
		    cin >> u >> v >> w;
		    graph[u][v] += w;
            graph[v][u] += w;
	    }
	    cout << "Network " << nt << endl;
    	cout << "The bandwidth is " << FordFulkerson(n, s, t) << '.'<< endl;	
        cout << endl; 
        memset(graph, 0, sizeof graph);
        memset(rgraph, 0, sizeof rgraph);
        memset(path, 0, sizeof path);
        
        cin >> n;
        nt++;
    }

	return 0;
}
