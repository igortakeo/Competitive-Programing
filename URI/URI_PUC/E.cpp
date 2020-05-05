#include <bits/stdc++.h>

using namespace std;

int main(){

	string str;
	
	while(getline(cin, str)){
		
		string ans = "";
		
		for (int i=0; i<str.size(); i++){
			if((str[i] == ',' or str[i] == '.') and ans.size() > 0 and ans.back() == ' ')ans.pop_back();
			ans+=str[i];
		}
		
		cout << ans << endl;
		
	}

	return 0;
}
