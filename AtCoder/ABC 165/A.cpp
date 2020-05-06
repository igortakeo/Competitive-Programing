#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	int k, a, b;
	cin >> k >> a >> b;
	
	for(int i=a; i<=b; i++){
		if(i%k == 0){
			cout << "OK" << endl;
			return 0;
		}
	}
	
	cout << "NG" << endl;
		
	      
	return 0;
}

