#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	int n, s;
	cin >> n >> s;
	
	vector<int>ans;
	int d = s-(n-1);
	
	if(n-1 >= d-1) cout << "NO" << endl;	 
	else{
		int k = s-n;
		ans.push_back(d);
		
		n--;
		while(n--)ans.push_back(1);
		
		cout << "YES" << endl;
		for(auto it : ans) cout << it << ' ';
		cout << endl; 
		cout << k << endl;
	} 
		
}

int main(){

	fastcin
	solve();      
	return 0;
}
	
