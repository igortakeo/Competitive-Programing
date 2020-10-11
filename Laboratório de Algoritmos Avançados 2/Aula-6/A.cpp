#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 30005
#define ll long long
using namespace std;

ll coins[5] = {1,5,10,25,50};
ll n;
ll dp[MAX];

void preCompute(){
	dp[0] = 1;
	for(int i=0; i<5; i++){
		for(int j=0; j<=30000; j++){
			if(coins[i] <= j)dp[j] += dp[j-coins[i]];	
		}	
	}	
}


int main(){
	
	preCompute();
	
	while(scanf("%lld", &n) != EOF){
		if(dp[n] == 1) printf("There is only 1 way to produce %lld cents change.\n", n);
		else printf("There are %lld ways to produce %lld cents change.\n", dp[n], n);	
	}
	
	return 0;
}
