#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


int x, n;

int solve(int i, int sum){
	if(sum == x) return 1;	
	if(sum > x or pow(i, n) > x) return 0;
	return solve(i+1, sum+pow(i, n)) + solve(i+1, sum);
}

int main(){

	fastcin
	cin >> x >> n;
	cout << solve(1,0) << endl;
	
	return 0;
}
	
