#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m;
	
	while(scanf("%d%d", &n, &m) != EOF){
		
		int h = (n*12)/360; 
		int i = (m*60)/360;
		
		
		if(h < 10) printf("0%d:", h);
		else printf("%d:", h);
		
		if(i < 10) printf("0%d\n", i);
		else printf("%d\n", i);
		
	}	
	

	return 0;
}
