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
		int n, x;
		cin >> n;
		
		deque<int>d;
		
		for(int i=0; i<n; i++){
			cin >> x;
			d.push_back(x);
		}
		
		
		
			
		int a=0, b=0, moves=1;
		int anta=0, antb=0;
		
		anta += d.front();
		a += anta;
		d.pop_front();
		
		while(!d.empty()){
			
			if(anta > 0){
				while(antb <= anta and !d.empty()){
					antb += d.back();
					d.pop_back();
				}
				b += antb;
				anta = 0;
			}
			else{
				while(anta <= antb and !d.empty()){
					anta += d.front();
					d.pop_front();
				}
				a += anta;
				antb = 0;
			}
				
			moves++;	
		}
		
		cout << moves << ' ' << a << ' ' << b << endl;
		
	}
	
		
	      
	return 0;
}
	
