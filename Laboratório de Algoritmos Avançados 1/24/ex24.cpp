#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


void b(string *s, int *x){
	string v = *s, aux;
	char a[2];
	if(v[v.size()-2] == ' '){
		aux = v.substr(v.size()-1, 1);
	}
	else{
		aux = v.substr(v.size()-2, 2);
	}
	
	for(int i=0;i<(int)aux.size(); i++) a[i] = aux[i];
	
	*s = v.substr(0,16);
	*x = atoi(a);
}

int main(){
	
	int leak = 0, position = 0, consumption = 0;
	double ans = 0, current = 0;
	
	while(true){
		int n;
		string s;
		
		cin >> n;
		cin.ignore();
		getline(cin, s);
		
		if(s[0] == 'F'){
			int x;
			
			b(&s, &x);
			
			if(s == "Fuel consumption" and n == 0 and x == 0) break;
			
			current += ((n-position)*consumption)/100.0 + leak*(n-position);
			position = n;
			consumption = x;
		}
		else{
			
			if(s == "Gas station"){
				
				current += ((n-position)*consumption)/100.0 + leak*(n-position);
				
				ans = max(ans, current);
				current = 0;
				position = n;
			}
			else if(s == "Mechanic"){
				
				current += ((n-position)*consumption)/100.0 + leak*(n-position);
				
				leak  = 0;
				position = n;
			}
			else if(s == "Leak"){
				
				current += ((n-position)*consumption)/100.0 + leak*(n-position);
				
				leak++;
				position = n;
			}
			else if(s == "Goal"){
				
				current += ((n-position)*consumption)/100.0 + leak*(n-position);
				ans = max(ans, current);
				
				printf("%.3lf\n", ans);	
				position  = 0;
				leak = 0;
				current = 0;
				ans = 0;
			}
		
		}
			
	}

	return 0;
}
