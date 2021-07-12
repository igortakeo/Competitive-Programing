#include <bits/stdc++.h> //On CodeSignal this include is not found
#define inf 0x3f3f3f3f //inf=1061109567
#define Max 100100
#define pii pair<int, int>
using namespace std;

//Problem Link: https://app.codesignal.com/company-challenges/uber/tucq8L9FB7QyDZ4M6

int n, m;
vector<pii>edges[Max];
int dist[Max];   
int vis[Max];

void dijkstra(int s){ 

	for(int i=0; i<n; i++) dist[i]=inf; 
	dist[s]=0;

	priority_queue<pii, vector<pii>, greater<pii>>queue;
	queue.push(make_pair(dist[s], s));
	
	while(true){
		int u=-1;	
		
		while(!queue.empty()){
			
			int a = queue.top().second;
			queue.pop();	
			
			if(!vis[a]){
				u = a;
				break;
			}
		}
		
		if(u == -1) break;
		vis[u] = true; 
		
		for(int i=0; i < (int)edges[u].size(); i++){
			
			int v = edges[u][i].first; 
			int w = edges[u][i].second;			
			if(dist[w] > dist[u]+v){
				dist[w] = dist[u]+v; 
				queue.push(make_pair(dist[w], w));
			}
		}
	}

}

//It's not necessary a main, the answer is return of nightRoute

int nightRoute(vector<vector<int>> city) {
    n = city.size();
    int count = 0;
    for(int i=0; i<city.size(); i++){
        for(int j=0; j<city[i].size(); j++){
            if(city[i][j] == -1) continue;
            pii v;
            v.first = city[i][j];
            v.second = j;
            edges[i].push_back(v);
            count++;
        }
    }
    m = count;
    
    dijkstra(0);
    
    return dist[n-1];

}
