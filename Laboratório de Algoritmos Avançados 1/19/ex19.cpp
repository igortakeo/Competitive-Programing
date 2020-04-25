#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#define ll long long
#define MAX 1000005
using namespace std;

int crivo[MAX+5];
int prime[700005], it;

void preCompute() {
    
    crivo[1] = 1;	    
    int n = 1000000;
    for(int i = 2; i <= n; i++) {
        if(!crivo[i]) {
            prime[it] = i; it++;
            for(int k = n/i, j = i*k; k >= i; k--, j -= i){
                crivo[j] = 1;
			}
        }
    }
}
int is_prime(int n) {
    
    if(n < 1000000)return !crivo[n];
    int r = (int)sqrt(n);
    for(int i = 0; i < it && prime[i] <= r; i++)
        if(n%prime[i] == 0)return 0;
    return 1;
}

int main(){

	ll l, u;
	
	preCompute();	
		
	while(scanf("%lld %lld", &l, &u) == 2){
		
		
		int diffMX=-MAX, diffMN=MAX;
		
		pair<ll, ll> luMN, luMX;
		int d=-1, v=-1;
		ll diff;
		ll i;
		for(i=l; i<=u; i++){	
			if(is_prime(i)){
				if(d == -1){
					d = i;
					continue;
				}
				if(v == -1) v = i;
				else{
					d = v;
					v = i;
				}
				
				diff = v-d;
			 
				if(diff > diffMX){
					luMX.first = d;
					luMX.second = v;
					diffMX = diff;
				}
			  
				if(diff < diffMN){
					luMN.first = d;
					luMN.second = v;
					diffMN = diff;
				}
			}
		 }
		 
		
		 if(diffMX == -MAX and diffMN == MAX) printf("There are no adjacent primes.\n");
		 else printf("%lld,%lld are closest, %lld,%lld are most distant.\n", luMN.first, luMN.second, luMX.first, luMX.second);
		
	}
	

	return 0;
}

