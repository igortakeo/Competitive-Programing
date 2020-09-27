#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){
	fastcin	
	int n, a, b, ans = 0;
    cin >> n >> a >> b;

    if(a+b == n){
        cout << 1 << endl;
        return 0;
    }

    int i=1; 

    while(i < n){
  
        int p1 = i, p2= n-i;
        int c1 = a/p1, c2 = b/p2;
           
        if(c1 == 0 or c2 == 0){i++;continue;}
        
        int m = min(a/p1, b/p2);

        ans = max(m, ans);
        i++;         
    }
    
    cout << ans << endl;

	return 0;
}
	

