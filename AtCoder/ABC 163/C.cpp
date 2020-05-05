#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	int n, x;
	cin >> n;
	
	int freq[n+1];
	
	memset(freq, 0, sizeof freq);
	
	for(int i=1; i<n; i++){
		cin >> x;
		freq[x]++;
	}
	
	for(int i=1; i<=n; i++) cout << freq[i] << endl;
		
	return 0;
}
