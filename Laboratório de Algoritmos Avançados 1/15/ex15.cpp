#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pb push_back
#define ppb pop_back
#define MAX 150
using namespace std;

vector<string> v;
vector<string> ans;
string a[150];
int n, m, sz;

void solve(int i,  string c){

	if(i == sz){
		for(auto it : ans) cout << it << ' ';
		cout << endl;		
		return;
	}	

	for(int k = 1; k+i <= sz; k++){
		string d = c.substr(i, k);
		if(find(v.begin(), v.end(), d) != v.end()){
			ans.pb(d);
			solve(i+k, c);
			ans.ppb();
		} 
	}

	return;
}

int main(){

	string x;

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.pb(x);
	}

	cin >> m;

	for(int i=0; i<m; i++) cin >> a[i];

	for(int i=0; i<m; i++){	
		sz = a[i].size();
		solve(0, a[i]);
		if(i+1 != m)cout << endl;		
	}
	
	return 0;
}