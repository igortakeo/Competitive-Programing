#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	int t;
	
	cin >> t;
	
	while(t--){
		
		int n, a, b, c, d;
		bool flag = true;
		cin >> n >> a >> b >> c >> d;
			
		int Ma = n*(a+b), Me= n*(a-b);
			
		for (int i=c-d; i<=c+d;	i++){
			if(i >= Me and i <= Ma){
				cout << "Yes" << endl;
				flag= false;
				break;
			}
		}
		
		if(flag) cout << "No" << endl;
		
		
	}
	      
	      
	      
	      
	return 0;
}
