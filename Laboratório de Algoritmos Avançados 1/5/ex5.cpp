#include <iostream>
#include <vector>
#include <cstring>
#define MAX 200001
using namespace std;

vector<int>edges[MAX];
int vis[MAX];

void dfs(int u) {
    vis[u] = 1;
    for(int i = 0; i < (int)edges[u].size(); ++i) {
        int v = edges[u][i];
        if(vis[v] == 0) dfs(v);
    }
}

int main(){

    int n;
    string s;
    cin >> n;

    int v[n];
 
    for(int i=0; i<n; i++) cin >> v[i];

    cin >> s;

    for(int i=1; i<=(n-1); i++){
        if(s[i-1] == '1') {
            edges[i].push_back(i+1);
            edges[i+1].push_back(i);
        }  
    }

    for(int i=1; i<=n; i++){
        dfs(i);
        if(vis[v[i-1]] == 0){
            cout << "NO" << endl;

    cout << "YES" << endl;

    return 0;
}