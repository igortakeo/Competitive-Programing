#include <string.h>
#include <iostream>
#include <stack>
using namespace std;

int main(){

	string s;
	stack<char>p;
	cin >> s;

	for(int i=0; i<(int)s.size(); i++){
		if(p.empty()) p.push(s[i]);
		else if(s[i] == ')' and p.top() == '(') p.pop();	
		else p.push(s[i]);
	}

	if(p.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}