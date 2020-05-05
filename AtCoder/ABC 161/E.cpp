#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int n, k, c;
string s;
set<vector<int>>ans;
int freq[MAX];

void solve(int i, vector<int>&v, string p){

	if(v.size() == k){
		ans.insert(v);
		return;
	}
	if(i >= n) return;
	
	if(p[i] == 'x') solve(i+1, v, p);
	else{
		
		v.push_back(i+1);
		for(int j=i+1; j<n and j-c<=i; j++)p[j] = 'x';
		solve(i+1+c, v, p);
		
		for(int j=i+1; j<n and j-c<=i; j++)p[j] = s[j];	
		v.pop_back();	
		solve(i+1, v, p);
		
	}
	
	return;		
}


int main(){
	
	cin >> n >> k >> c;
	cin >> s;
	
	vector<int>v;
	string p = s;
	solve(0, v, p);
		
	for(auto a: ans){
		vector<int>ap = a;
		for(auto it : ap) freq[it]++;
	}
	
	for(int i=1;i<=n; i++){
		if(freq[i] == ans.size()) cout << i << endl;
	}
	
	return 0;
}
