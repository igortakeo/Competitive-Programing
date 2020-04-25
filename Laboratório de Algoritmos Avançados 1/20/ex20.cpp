#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#define ll long long
#define MOD 131071
using namespace std;

ll ModularExponentiation(ll x, ll n){
	if(n == 0) return 1;
	else if(n%2 == 0) return ModularExponentiation((x*x)%MOD, n/2);
	else return (x*ModularExponentiation((x*x)%MOD, (n-1)/2))%MOD;
}

string ReadString(){
	
	string s = "";
	char c;
	while(scanf("%c", &c) != EOF){
		if(c == '#')break;
		if(c == '\n') continue;
		s += c;
	}
	return s;
}

int main(){
	
	while(true){
		
		string s = ReadString();
		if(s == "")break;
		
		reverse(s.begin(), s.end());
		
		int sum = 0;
		string ans;
		
		for(int i=0; i<(int)s.size(); i++){
			int x = s[i] - '0';
			sum += ModularExponentiation(2, i)*x;
		}
		
		(sum%MOD == 0) ? ans = "YES" : ans = "NO"; 

		cout << ans <<endl;
	}	
		
	
	return 0;
}
