#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


ll w, x, y;

void extendEucld(ll A, ll B){
	if(B == 0){
		w = A;
		x = 1;
		y = 0;
	}
	else{
		extendEucld(B, A%B);
		int temp = x;
		x = y;
		y = temp-(A/B)*y;
	}
}

ll ModularExponentiation(ll x, ll n, ll m){
	if(n == 0) return 1;
	else if(n%2 == 0) return ModularExponentiation((x*x)%m, n/2, m);
	else return (x*ModularExponentiation((x*x)%m, (n-1)/2, m))%m;
}

ll modInverse(ll A, ll M){		
	  w = 0; x=0; y=0;
	  extendEucld(A, M);
	  return (x%M + M)%M;  
}

int phi(int n){
	double totient = n;
	
	for(int i=2; i*i<=n; i++){
		if(n%i == 0){
			while(n%i == 0) n/=i;
			totient *= (1.0 -(1.0/(double)i));
		}
	}
	if(n>1) totient *= (1.0 -(1.0/(double)n));
	return (int)totient;
}

void solve(ll n, ll e, ll c){
	ll tot = phi(n);
	ll d = modInverse(e, tot);
	cout << ModularExponentiation(c, d, n) << endl;		
}

int main(){

	fastcin
	
	ll n, e, c;
	
	while(scanf("%lld %lld %lld", &n, &e, &c) != EOF) solve(n,e,c);
	      
	return 0;
}
	

