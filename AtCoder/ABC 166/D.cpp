#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	ll x;
	cin >> x;	
	
	for(ll i = -200; i<=200; i++){
		for(ll j = -200; j<=200; j++){
			if((i*i*i*i*i)-(j*j*j*j*j) == x){
				cout << i << ' ' << j << endl;
				return 0;
			}	
		}
	}
	
	return 0;
}
