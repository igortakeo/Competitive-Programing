#include <bits/stdc++.h>
#define MAX 500100
#define MAXN 5000000
#define MOD (int)(1e9 + 7)
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll BIT[MAXN], arrayPHI[MAX], arrayPillai[MAX], n;

double phi(ll x){
	double totient = x;
	
	for(ll i=2; i*i<=x; i++){
		if(x%i == 0){
			while(x%i == 0) x/=i;
			totient *= (1.0 -(1.0/(double)i));
		}
	}
	if(x>1) totient *= (1.0 -(1.0/(double)x));
	return totient;
}

void computeTotientFunction(){
	for(ll i=1; i<MAX; i++){
		arrayPHI[i] = phi(i);	
	}
}

void computePillaiFunction(){
	for(ll i = 1; i<MAX; i++){
	    for(ll j = i; j < MAX; j+=i){
            arrayPillai[j] += i*arrayPHI[j/i];
        }
	}
}
		
void update(ll x, ll new_value){
	for(; x <= n; x+= x&-x) BIT[x] += new_value;
}

ll query(ll x){
	ll sum = 0;
	for(; x > 0; x-=x&-x) sum += BIT[x];
	return sum; 	
}


int main(){
	
	fastcin
	
	computeTotientFunction();
	computePillaiFunction();

	cin >> n;	
	ll v[n+1];
		
	for(int i=1; i<=n; i++){
		cin >> v[i];
		ll s = arrayPillai[v[i]];
		update(i, s);	
	}
		
	int q;
	cin >> q;
	
	char c;
	int x, y;
	
	while(q--){
		cin >> c;
		cin >> x >> y;
		
		if(c == 'C'){
			cout << (query(y) - query(x-1))%MOD << endl;	
		}
		else{
			ll upd1 = 0, upd2 = 0;
			upd1 = arrayPillai[v[x]];
			upd2 = arrayPillai[y];
			
			v[x] = y;
			update(x, upd2 - upd1);
		}
	}
		

	return 0;
}
