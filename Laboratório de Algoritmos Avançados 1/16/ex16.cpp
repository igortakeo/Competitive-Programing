#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

int main(){
	
	
	ll n;
	cin >> n;
	while(n != 0){

		if(n<0)n*=-1;

		set<ll>v;
		for(ll i=2; i*i <= n; i++){
			ll c = 0;
			while(n%i == 0){
				c++;
				n/=i;
			}
			if(c != 0) v.insert(i);
		}
		if(n>1){ 
			v.insert(n);
		}


		if(v.size() < 2) cout << -1 << endl;
		else{
			auto a = v.end();
			a--;
			cout << *a << endl;
		} 


		cin >> n;
	}

	
	return 0;
}