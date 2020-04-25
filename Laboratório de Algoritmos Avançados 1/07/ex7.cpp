#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define pb push_back
#define pii pair<int, int>

using namespace std;

map<int, int>m;

int main(){

    int k;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    string s;
    
    cin >> s;

    while(s != "#"){
        int x, y;
        cin >> x >> y;
        pq.push(make_pair(y,x));
        m[x] = y;
        cin >> s;
    }    

    cin >> k;
    vector<int>ans, aux;
    
    for(int i=0; i<k; i++){
        pii v = pq.top();
        int w = v.first;
        aux.pb(v.second);
        pq.pop();
        v.first+=m[v.second];
        pq.push(v);
        
        while(w == pq.top().first){
            v = pq.top();                
            aux.pb(v.second);
            pq.pop();
            v.first+=m[v.second];
            pq.push(v);
        }
        sort(aux.begin(), aux.end());

        for(int j=0; j < (int)aux.size(); j++) ans.pb(aux[j]);
        aux.clear();
    }


    for(int i=0; i<k; i++) cout << ans[i] << endl;

    return 0;
}

