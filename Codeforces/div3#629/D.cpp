#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>ans;
bool flag;

void solve(vector<int>&v, int i, int aux[]){

	if(i == n){
		if(((aux[n-1] != aux[0] and v[n-1] != v[0]) or (v[n-1] == v[0])) and !flag){
			flag = true;
			for(int j=0; j<n; j++) ans.push_back(aux[j]);
			return;
		}
		else return;
	}
	if(i == 0){
		aux[i]=1;	
		return solve(v, i+1, aux);
	}
	if(v[i-1] != v[i]){
		if(aux[i-1] == 1) aux[i] = 2;
		else aux[i] = 1;
		return solve(v, i+1, aux);
	}
	for(int j=1; j<=2; j++){
		aux[i]= j;
		solve(v, i+1, aux);
	}	

}


int main(){

	int t;
	cin >> t;

	while(t--){
		
		cin >> n;

		vector<int>v(n);
		int aux[n];
		memset(aux, 0, sizeof aux);

		for(int i=0; i<n; i++) cin >> v[i];
		
		bool f = false;
		int as = 0;

		for(int i=1; i<n; i++){
			if(v[i-1] != v[i]){f = true; break;}
		}

		if(!f){
			as=1;
			for(int i=0; i<n; i++)ans.push_back(1);
		}
		else if(n%2 == 0){
			as = 2;
			for(int i=0; i<n; i++)ans.push_back(i%2 == 0 ? 1 : 2);
		}
		else{
			bool g = false;

			for(int i=1; i<n; i++){
				if(v[i-1] == v[i]){g = true; break;}
			}		
			if(v[n-1] == v[0]) g= true;

			if(!g){
				as = 3;
				for(int i=0; i<n-1; i++)ans.push_back(i%2 == 0 ? 1 : 2);
				ans.push_back(3);
			}
			else{
				as = 2;
				flag = false;
				solve(v, 0, aux);
			}			

		}

		cout << as << endl;
		for(auto a : ans) cout << a << ' ';
		cout << endl;	

		ans.clear();
		
	}




	return 0;
}