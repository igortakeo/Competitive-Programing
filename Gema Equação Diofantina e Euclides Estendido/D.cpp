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
	
    while(true){
        ll n;
        cin >> n;
        
        if(n == 0) break;
    
        ll c1, n1, c2, n2;
        cin >> c1 >> n1 >> c2 >> n2;

        if(n%__gcd(n1, n2) != 0){
            cout << "failed" << endl;
            continue;
        }

        d = 0; x = 0; y = 0;
        
        extendEucld(n1, n2);      
        
        double p = n/(double)d;
        double x_0 = x*p, y_0 = y*p;
        double t_1, t_2;        
        double f = n1/(double)d, g = n2/(double)d;        
        
    
        t_1 = -x_0/g;
        t_2 = y_0/f;
       
        double l = min(t_1, t_2);
        double r = max(t_1, t_2);
            
        ll ans_xr = x_0 + g*floor(r), ans_yr = y_0 - f*floor(r);
        ll ans_xl = x_0 + g*ceil(l), ans_yl = y_0 - f*ceil(l);        
       
        if((ans_xr < 0 or ans_yr < 0) and (ans_xl < 0 or ans_yl < 0)) cout << "failed" << endl;
        else if(ans_xr < 0 or ans_yr < 0) cout << ans_xr << ' ' << ans_yr << endl;
        else if(ans_xl < 0 or ans_yl < 0) cout << ans_xl << ' ' << ans_yl << endl;
        else if(ans_xr*c1+ans_yr*c2 <= ans_xl*c1 + ans_yl*c2){
            cout << ans_xr << ' ' << ans_yr << endl;
        }
        else cout << ans_xl << ' ' << ans_yl << endl;
        
    }

	return 0;
}
