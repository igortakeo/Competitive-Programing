#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	string s = "", ans = "";
	char one='1', zero='0';
	
	
	if(b == 0){
		if(a > 0 and  c == 0){
			s = string(a+1, zero);
			cout << s << endl;
			return; 
		}
		else if(c > 0 and  a == 0) {
			s = string(c+1, one);
			cout << s << endl;
			return;
		}
	}

	for(int i=0; i<=b; i++){
		if(i%2 == 0) s +=one;
		else s+=zero;
	}	
	
	string o = string(c, one), z = string(a, zero);
	
	s.insert(1, z);
	s.insert(0, o);
	
	cout << s << endl;
	
	return;		
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	while(t--) solve();
		
	return 0;
}
	

