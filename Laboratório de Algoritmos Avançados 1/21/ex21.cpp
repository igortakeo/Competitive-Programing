#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
		
	int t;

	cin >> t;
	cin.ignore();
	while(t--){
		string s, q;
		getline(cin, s);
		
		vector<int>v;
		
		int x = 0, j = 0, ans = -1;
		for(int i=0; i < (int)s.size(); i++){
			if(s[i] ==' '){
				q = s.substr(j, i-j);
				x = stoi(q);
				v.push_back(x);
				j = i+1;
			}
		}
		q = s.substr(j, s.size()-j);
		x = stoi(q);
		v.push_back(x);
		
		for(int i=0; i<(int)v.size(); i++){
			for(int k=i+1; k<(int)v.size(); k++) ans = max(__gcd(v[i], v[k]), ans);
		}
		
		
		cout << ans << endl;
		
	}	
	
	return 0;
}
