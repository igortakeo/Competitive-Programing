#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
		
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		vector<int>ans;
		cin >> n >> k;
		
		if(k > n) cout << "NO" << endl;
		else if(k == n){
			for(int i=0; i<k; i++)ans.push_back(1);
			cout << "YES" << endl;
			for(auto a : ans) cout << a << ' ';
			cout << endl;
		}
		else{
			int diff1 = n-(k-1);
			int diff2 = n-(2*(k-1));
			
			if(diff1%2 != 0 and diff1 > 0){
				for(int i=0; i<k-1; i++)ans.push_back(1);
				ans.push_back(diff1);
				cout << "YES" << endl;
				for(auto a : ans) cout << a << ' ';
				cout << endl;
				
			}
			else if(diff2%2 == 0 and diff2 > 0){
				for(int i=0; i<k-1; i++)ans.push_back(2);
				ans.push_back(diff2);
				cout << "YES" << endl;
				for(auto a : ans) cout << a << ' ';
				cout << endl;
				
			}
			else cout << "NO" << endl;
				
		}
		
	}	
		
	      
	return 0;
}
	
