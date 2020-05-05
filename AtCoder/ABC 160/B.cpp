#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main(){

	ll n, ans = 0;
	cin >> n;

	ans += (n/500) * 1000;

	n -= (n/500)*500;

	ans += (n/5)*5;


	cout << ans << endl;

	return 0;
}