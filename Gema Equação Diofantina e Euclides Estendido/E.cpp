#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


ll d, x, y;

void extendEucld(ll A, ll B){
	if(B == 0){
		d = A;
		x = 1;
		y = 0;
	}
	else{
		extendEucld(B, A%B);
		int temp = x;
		x = y;
		y = temp-(A/B)*y;
	}
}

int main(){
	fastcin	
	ll a, b, ans=(ll)2e18, lcm;
    cin >> a >> b;

    ll gcd = __gcd(a,b);
     
    if(a == 1 and b == 1){
        cout << 1 << endl;
        return 0;
    }
    else if(a == 1 or b == 1){
        cout << 2 << endl;
        return 0;
    }

    else if(gcd == 1){
        extendEucld(a,-b);
           
        ans = max(abs(x*a), abs(b*y));
        //if(ans == abs(x*a)) ans = abs(((x+b)%b)*a);
        //else ans = abs(((y+a)%a)*b);
    }
    
    lcm = a*b/gcd;

    cout << min(lcm, ans) << endl;

	return 0;
}
 	
