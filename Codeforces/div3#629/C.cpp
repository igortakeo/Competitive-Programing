#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		string s;
		cin >> s;

		char t1[n], t2[n];

		int j=n;
		for(int i=0; i<n; i++){
			if(s[i] == '2'){
				t1[i] = '1';
				t2[i] = '1';
			}
			else if(s[i] == '0'){
				t1[i] = '0';
				t2[i] = '0';
			}
			else{
				t1[i] = '1';
				t2[i] = '0';
				j = i+1;
				break;
			}
		}	

		for(int k = j; k<n; k++){
			t2[k] = s[k];
			t1[k] = '0';
		}

		for(int i=0; i<n; i++) cout << t1[i];
		cout << endl;
		for(int i=0; i<n; i++) cout << t2[i];
		cout << endl;
	}




	return 0;
}