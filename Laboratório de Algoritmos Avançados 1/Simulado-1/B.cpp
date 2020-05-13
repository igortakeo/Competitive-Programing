#include <iostream>
#define ll long long
using namespace std;

ll u, n, cnt=0;

void up(ll s){

	while(true){
		string v = to_string(s);
		int sum = 0;
		for(int i=0; i<v.size(); i++) sum+=(ll)v[i]-'0';

		if(sum == 10) cnt++;
			
		if(sum == 10 and  cnt == n){
			u = s;
			return;
		}
		s++;
	}
	
}

int main(){

	cin >> n;	
	up(1);
	
	cout <<  u << endl;

	return 0;
}