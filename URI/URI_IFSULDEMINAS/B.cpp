#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin >> t;
		
	while(t--){
		string s;
		cin >> s;
		
		char c[4] = {'Q', 'J', 'K', 'A'};
		int j = 0;
		
		for(int i=0; i<s.size(); i++){
			if(j == 4) break;
			
			if(s[i] == c[j]) j++;	

		}	
		
		if(j == 4) cout << "Agora vai" << endl;
		else cout << "Agora apertou sem abracar" << endl;	
		
	}	

	return 0;
}
