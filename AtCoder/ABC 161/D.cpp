#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int m[3] = {-1,0,1};

string solve(vector<string>&v, int i, int cnt){
	
	int u = v[i].back() - '0';
	
	for(int j=0; j<3; j++){
		if((u == 0 and j == 0) or (u == 9 and j == 2)) continue;
		
		int d  = u + m[j];
		char c  = d + '0';
		string s = v[i]+c;
		v.push_back(s);
		cnt++;
		if(cnt == n){
			return s;
		}	
	}
	
	return solve(v, i+1, cnt);
	
}

int main(){
	
	cin >> n;
	
	vector<string>v {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
	
	if(n <=9) cout << v[n-1] << endl;
	else cout << solve(v, 0, 9) << endl;
	
	return 0;
}
