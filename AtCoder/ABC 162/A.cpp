#include <bits/stdc++.h>

using namespace std;
int main(){
	
	string n;
	cin >> n;
	
	bool flag = false;
	
	for(int i=0; i<n.size(); i++){
		if(n[i] == '7'){
			flag = true;
			break;
		}
	}
	
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	
	return 0;
}
