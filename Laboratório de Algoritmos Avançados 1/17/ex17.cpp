#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int, int>
using namespace std;

ll solve(ll n, ll p){
	
    ll res = 0;
    for (ll power = p ; power <= n ; power *= p) res += n/power;
    return res;
}

int main(){

	ll n, m;
	int z = 0;
	while(scanf("%lld %lld", &n, &m) != EOF){
		if(z > 0) cout << endl;		
		vector<pii>v;
		ll p = m;
		for(ll i=2; i*i <= m; i++){
			int c = 0;
			while(m%i == 0){
				c++;
				m/=i;
			}
			if(c != 0) v.push_back(pii(i, c));
		}
		if(m>1){  
			v.push_back({m, 1});
		}
		
		bool flag = true;
		for(ll i=0; i<(int)v.size(); i++){
			if(solve(n, v[i].first) < v[i].second){
				flag = false;
				break;
			}	
		}      
		
		if((flag and p != 0) or n >= p) printf("%lld divides %lld!", p, n);
		else printf("%lld does not divide %lld!", p, n);
		z++;		
	}                                             
	                                   
	                                      
	return 0;
}
