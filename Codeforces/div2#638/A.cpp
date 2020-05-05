#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int power[35];

int main(){

	fastcin
	
	for(int i=1; i<=30; i++) power[i] = pow(2,i);	
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		vector<int> p1, p2;
		p1.push_back(power[n]);
		
		for(int i=n-1;i>=(n-n/2); i--) p2.push_back(power[i]);
		for(int i=1;i<=(n-n/2)-1; i++)p1.push_back(power[i]);
		
		ll a=0, b=0;
		
		for(auto it : p1) a += it;
		for(auto it : p2) b += it;
		
		cout << abs(a-b) << endl;
		
	}
		
	 
	return 0;
}

