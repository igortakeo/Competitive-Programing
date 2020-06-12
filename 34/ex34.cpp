#include <iostream>
#include <vector>
#include <string.h>
#define MAX 5000
#define inf 0x3f3f3f3f 
using namespace std;

struct edges{
	int x, y, weight;
};

vector<edges>edges_bellford;
int dist[MAX];
int number_vertex;


bool bellmanford(int u){
	
	for(int i=1; i<= number_vertex; i++) dist[i] = inf;
	dist[u] = 0;
	for(int i=0; i < number_vertex-1; i++){
		bool flag = false;
		for(auto v : edges_bellford){
			if(dist[v.x] != inf && dist[v.x]+v.weight < dist[v.y]){
				dist[v.y] = dist[v.x] + v.weight;
				flag  = true;
			}	
		}
		if(!flag)break; 
	}
	
	for(auto v : edges_bellford){
		if(dist[v.x] != inf && dist[v.x]+ v.weight < dist[v.y]) return true;
	}	
	
	return false;
}


void solve(){
	int m;
	cin >> number_vertex >> m;
	
	for(int i=0; i<m; i++){
		struct edges e;
		cin >> e.x >> e.y >> e.weight;
		edges_bellford.push_back(e);
	}
	
	if(bellmanford(0)) cout << "possible" << endl;
	else cout << "not possible" << endl;
	
	edges_bellford.clear();
	memset(dist, 0, sizeof dist);
}


int main(){
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}
