#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
int main(){
 
	fastcin
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	string v[n];
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	
	bool flag = true;
	char ans[n];
	for(int i=0; i<n; i++){
		string s = v[i];
		
		if(s == "AB"){
			
			if(a == 0 and b == 0){
				flag = false;
				break;
			}
			
			if(a == 1 and b == 1 and c == 0 and i+1 < n){
				if(v[i+1] == "BC"){
					b++;
					a--;
					ans[i] = 'B';
				}
				else if(v[i+1] == "AC" or v[i+1] == "AB"){
					a++;
					b--;
					ans[i] = 'A';
				}
			}
			else if(a <= b){
				a++;
				b--;
				ans[i] = 'A';
			}
			else{
				b++;
				a--;
				ans[i] = 'B';
			}
			
		}
		else if(s == "AC"){
			
			if(a == 0 and c == 0){
				flag = false;
				break;
			}
			
			if(a == 1 and b == 0 and c == 1 and i+1 < n){
				if(v[i+1] == "BC"){
					c++;
					a--;
					ans[i] = 'C';
				}
				else if(v[i+1] == "AC" or v[i+1] == "AB"){
					a++;
					c--;
					ans[i] = 'A';
				}
			}
			else if(a <= c){
				a++;
				c--;
				ans[i] = 'A';
			}
			else{
				c++;
				a--;
				ans[i] = 'C';
			}
		}
		else{
			
			if(b == 0 and c == 0){
				flag = false;
				break;
			}
			
			if(a == 0 and b == 1 and c == 1 and i+1 < n){
				if(v[i+1] == "AB"){
					b++;
					c--;
					ans[i] = 'B';
				}
				else if(v[i+1] == "AC" or v[i+1] == "BC"){
					c++;
					b--;
					ans[i] = 'C';
				}
			}
			else if(b <= c){
				b++;
				c--;
				ans[i] = 'B';
			}
			else{
				c++;
				b--;
				ans[i] = 'C';
			}
		}	
		
		
	}
	
	if(!flag) cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		
		for(int i=0; i<n; i++) cout << ans[i] << endl;
	}
	
	      
	return 0;
}
