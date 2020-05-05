#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX (int)3e4
using namespace std;

struct no{
	int a, b, c;
};

vector<int>divisors[MAX];
vector<no>possibilities;

void preCompute(){
	
	for(int i=1; i<MAX; i++){
		int n = i;
		for(int j=1; j*j <= n; j++){
			if(n%j == 0){
				divisors[n].pb(j);		
				if(j != (n/j))divisors[n].pb(n/j);
			}
		}
	}
	
	for(int i=1; i<MAX; i++){
		for(int j=0; j< divisors[i].size(); j++){
			for(int k=0; k<divisors[divisors[i][j]].size(); k++){
				struct no v;
				v.a = divisors[divisors[i][j]][k];
				v.b = divisors[i][j];
				v.c = i;
				possibilities.pb(v);
			}	
		}
	}		
	
}

int main(){

	fastcin
		
	preCompute();	
	
	int t;
	
	cin >> t;
	while(t--){
		int a, b, c, ans = MAX;
		int ansa, ansb, ansc;
		cin >> a >> b >> c;
				
		for(int i=0; i<possibilities.size(); i++){
			int p = abs(a-possibilities[i].a) + abs(b-possibilities[i].b) + abs(c-possibilities[i].c);
			if(p < ans){
				ans = p;
				ansa = possibilities[i].a;
				ansb = possibilities[i].b;
				ansc = possibilities[i].c;
			} 	
		}
		
		cout << ans << endl;
		cout << ansa << ' ' << ansb << ' ' << ansc << endl;
		
	}
	
		  
	return 0;
}

