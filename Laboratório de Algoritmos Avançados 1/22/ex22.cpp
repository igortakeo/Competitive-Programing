#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
	
	int step, mod;
	
	while(scanf("%d %d", &step, &mod) != EOF){
		
		bool freq[mod+5], flag = true;
		memset(freq, false, sizeof freq);
		
		int i = 0;
		
		while(!freq[i]){
			freq[i] = true;
			i = (i+step)%mod;	
		}
		
		for(int i=0; i<mod; i++){
			if(!freq[i]){
				flag = false;
				break;
			}
		}

		if(flag){
            printf("%10d%10d    Good Choice\n\n", step, mod);
		}
		else{
			printf("%10d%10d    Bad Choice\n\n", step, mod);
		}
		
	}
	
	
	
	return 0;
}
