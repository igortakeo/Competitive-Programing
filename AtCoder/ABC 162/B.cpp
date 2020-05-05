#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	
	ll n, sum = 0;
	cin >> n;
	for(int i=1; i<=n; i++){
		if(i%3 == 0 or i%5 == 0) continue;
		sum += i;
	}	
	
	cout << sum << endl;
	
	
	return 0;
}
