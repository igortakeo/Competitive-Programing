#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		vector<pii>v;
		for(ll i=2; i*i <= n; i++){
			int c = 0;
			while(n%i == 0){
				c++;
				n/=i;
			}
			if(c != 0) v.push_back(pii(i, c));
		}
		if(n>1){  
			v.push_back({n, 1});
		}
		
		long long u[3];
		bool flag = false;
		
		if(v.size() >= 3){
			flag = true;
			u[0] = pow(v[0].first, v[0].second);
			u[1] = pow(v[1].first, v[1].second);
			u[2] = 1;
			for(int i=2; i<v.size(); i++) u[2]*=pow(v[i].first, v[i].second);
		} 
		else if(v.size() == 2 and (v[0].second > 1 or v[1].second > 1)){
			flag = true;
			if(v[0].second >1){
				u[0] = v[0].first;
				u[1] = pow(v[0].first, v[0].second-1);
				u[2] = pow(v[1].first, v[1].second);
				
				if(u[0] == u[1] and v[1].second > 1){
					u[1] = v[1].first;
					u[2] = pow(v[1].first, v[1].second-1)*v[0].first;
				}	
			}
			else{
				u[0] = v[1].first;
				u[1] = pow(v[1].first, v[1].second-1);
				u[2] = pow(v[0].first, v[0].second);
					
				if(u[0] == u[1] and v[0].second > 1){
					u[1] = v[0].first;
					u[2] = pow(v[0].first, v[0].second-1)*v[1].first;
				}
			}
		}
		else if(v.size() == 1 and v[0].second >= 6){
			flag = true;	
			u[0] = v[0].first;
			u[1] = pow(v[0].first, 2);
			v[0].second -= 3;
			u[2] = pow(v[0].first, v[0].second);
		}
		
		for(int i=0; i<3; i++){
				int p = u[i];
				for(int j=i+1; j<3; j++){
					if(p == u[j]) flag = false;
				}
			} 
			
		if(flag){
			cout << "YES" << endl;
			for(int i=0; i<3; i++) cout << u[i] << ' ';
			cout << endl;
		}
		else cout << "NO" << endl;
		
	}
	
	return 0;
}
