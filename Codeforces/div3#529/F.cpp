#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX 200005
#define N 1e12+5
#define pll pair<ll,ll>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll p[MAX];

ll find(ll x){
	if(p[x] == x) return x;		
	return  p[x]=find(p[x]); 
} 

bool join(ll x, ll y){
	
	x = find(x); 
	y = find(y); 		
	if(x==y) return false; 
	p[x] = y;
	return true;
}
int main(){

	fastcin
		
	ll n, m, ans=0;
	cin >> n >> m;
	
	ll v[n+1];
	
	vector<pair<ll, pll>> q;
	
	for(int i=1; i<=n; i++) cin >> v[i];
	
	int s;
	ll aux=N;
	for(int i=1; i<=n; i++){
		if(v[i] < aux){
			aux = v[i];
			s = i;
		}
	}
	
	for(int i=1;i<=n; i++)p[i]=i;
	
	for(int i=1; i<=n; i++){
		if(i == s) continue;
		
		q.push_back({v[s] + v[i],{s, i}});
	}
	
	ll x, y, w;
	
	while(m--){
		cin >> x >> y >> w;
		q.push_back({w,{x,y}});		
	}
	
	sort(q.begin(), q.end());
	
	for(int i=0; i<q.size(); i++){		
		if(join(q[i].second.first, q[i].second.second))ans+=q[i].first;
	}	
		
	cout << ans << endl;	
 
	return 0;
}

