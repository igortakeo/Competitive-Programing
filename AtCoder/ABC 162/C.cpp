#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	
	int k;
	ll sum = 0;
	cin >> k;
	
	for(int i=1; i<=k; i++){
		for(int j=1; j<=k; j++){
			int a = __gcd(i, j);		
			for(int l=1; l<=k; l++){
				sum+= __gcd(a, l);
			}
		}
	}
	
	cout << sum << endl;	
	
	return 0;
}
