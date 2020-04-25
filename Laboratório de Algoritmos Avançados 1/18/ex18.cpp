#include <iostream>
#include <algorithm>  
#define ll long long
using namespace std;

ll ModularExponentiation(ll x, ll n, ll m){
	if(n == 0) return 1;
	else if(n%2 == 0) return ModularExponentiation((x*x)%m, n/2, m);
	else return (x*ModularExponentiation((x*x)%m, (n-1)/2, m))%m;
}

bool is_prime(ll n){
	if(n == 0 or n == 1 or n < 0) return false;
	
	for(ll i=2; i*i<=n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	
	ll n;
	cin >> n;
	int z = 0;
	while(n != 0){
		//if(z > 0) cout << endl;
		bool flag = true;	
		
		if(is_prime(n)) cout << n << ' ' << "is normal.\n";
		else{			
			for(ll i=2; i <= n-1; i++){
				if(__gcd(i, n) == 1){
					if(ModularExponentiation(i, n-1, n) != 1){flag = false; break;}	
				}
			}
			if(flag) cout << "The number" <<' '<< n << ' ' << "is a Carmichael number.\n";
			else cout << n << ' ' << "is normal.\n";
		}
		 	
		//z++;
		cin >> n;
	}

	
	return 0;
}
