#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	while (t--){
		string s;
		
		cin >> s;	
		
		map<char, int>m;
		
		for(int i=0; i<s.size(); i++)m[s[i]] = 5;
	
		
		if(m['K'] == 5 and m['J'] == 5 and m['A'] == 5 and m['Q'] == 5) cout << "Aaah muleke" << endl;
		else cout <<  "Ooo raca viu" << endl;
	
		
	}
	

	return 0;
}
