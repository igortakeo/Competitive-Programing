#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<int>ans;
vector<int>depth(31);
int n, d;

void solve(vector<int>&v, int i, int j, int sum){
	for(auto a : v) cout << a << ' ';
	cout<< endl;
	if(sum == d and i == n-1){
		ans = v;
		return;
	}
	if(i == n-1 or sum > d) return;

	if(depth[j] == 0)j++;
	
	if(ceil((pow(2,j)-(depth[j]-1))/2.0) <= pow(2,j-1)-depth[j-1]){	
		v[i] = j;
		depth[j]--;
		solve(v, i+1, j, sum+j);
		depth[j]++;
	}
	j++;
	
	if(ceil((pow(2,j)-(depth[j]-1))/2.0) <= pow(2,j-1)-depth[j-1]){			
		v[i] = j;
		depth[j]--;
		solve(v, i+1, j, sum+j);
		depth[j]++;
	}
				
	return;
}

int main(){

	fastcin
	int t;
	cin >> t;
	
	depth[1] = 2;
	for(int i=2; i<=30; i++){
		depth[i] = depth[i-1]*2;
	}
	 
	while(t--){		
		
		cin >> n >> d;
		vector<int>v(n-1);	
		int freq[n+1];
		memset(freq, 0, sizeof freq);
			
		solve(v,0,1,0);		
		
		if(ans.size() == 0) cout << "NO" << endl;
		else{
			
			int ansf[n];
			int parent = 1, ant=2;
			ansf[0] = parent;
			for(int i=1; i<ans.size(); i++){
				if(ans[i-1] != ans[i]){
					parent = ant;
					ant = i+2;
				}
				if(freq[parent] == 2)parent++;
				ansf[i] = parent;
				freq[parent]++;
			}	
			cout << "YES" << endl;
			for(int i=0; i<n-1; i++) cout << ansf[i] << ' ';
			cout << endl;
			
		}
		ans.clear();
	  }
	  
	return 0;
}

