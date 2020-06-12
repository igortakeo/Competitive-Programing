#include <iostream>
#define Max 1001001
using namespace std;
 
int pai[Max], qtd[Max];
 
int find(int x){
	if(pai[x] == x) return x;		
	return  pai[x]=find(pai[x]);
} 
void join(int x, int y){
	x = find(x); 
	y = find(y); 		
	if(x==y) return;
	else{
		pai[x]=y;
		qtd[y]+= qtd[x];
	}	
}
int main(){
	int n, m, j;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		pai[i]=i;
		qtd[i]=1;
	}
	
	while(m--){
		cin >> j;
		int a[j];
		for(int i=0; i<j; i++) cin >> a[i];
		for(int k=1; k<j; k++) join(a[0],a[k]);	
	}
		
	for(int i=1; i<=n; i++) cout << qtd[find(i)] << ' ';
	cout << endl;
	return 0;
}
