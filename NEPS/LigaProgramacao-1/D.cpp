#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX (int)1e9+5
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<tuple<int, int, int>>v;
bool flag;
	
int distance(int x1, int x2){
	int d;	
	if(x1 >= 0 and x2 >= 0) d = max(x1, x2) - min(x1,x2);
	else if(x1 < 0 and x2 < 0){
		int aux1=x1*-1, aux2=x2*-1;
		d = max(aux1, aux2) - min(aux1,aux2);
	}
	else if(x1 >= 0 and x2 < 0) d = x1-x2;
	else if(x1 < 0 and x2 >= 0) d = x2-x1;
	return d;	
}

bool check(int cut, int k){
	int ans = 0;
	for(auto it : v){
		int b = get<0>(it);	
		int h = distance(get<1>(it), min(get<2>(it), cut));
		ans += h*b;		
	}
	if(ans >= k) return true;
	else return false;
}


void solve(){
	int n, k, miny=MAX, maxy=-MAX;
	cin >> n >> k;
	
	int x1, y1, x2, y2;
	for(int i=0; i<n; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		int d = distance(x1, x2);
		maxy = max(maxy, y2);
		miny = min(miny, y1);
		v.push_back(make_tuple(d, y1, y2));
	}
	
	int l=miny, r = maxy; 	 
	flag = false;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid, k)){r = mid-1; flag=true;}
		else l= mid+1;
	}	
	
	if(flag)cout << l << endl;
	else cout << "PERDAO MEU REI" << endl;
}

int main(){

	fastcin
	solve();      
	return 0;
}
	
