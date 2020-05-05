#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int sum[32];

int main(){

	fastcin
	sum[0] = 1;
		
	for(int i=1; i<32; i++)	sum[i] += pow(2,i) + sum[i-1];
		
	int t;
	cin >> t;
	
	while(t--){
		int n, ans=0;
		cin >> n;
		
		for(int i=1; i<32; i++){
			if(n%sum[i] == 0){
				ans = n/sum[i];
				break;
			}
		}
		
		cout << ans << endl;
	
	}	
			
		
	
	      
	return 0;
}
