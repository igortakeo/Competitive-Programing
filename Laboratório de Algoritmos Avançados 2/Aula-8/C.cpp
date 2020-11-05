#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pdi pair<double, int>
#define inf 0x3f3f3f3f 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
map<int, pii>dimsum;
int n, x, t, k;
int money;
int dp[11010][201][25];

int solve(int id, int sum_price, int plates){
    if(id > 2*k or plates > 2*(n+1) or sum_price > money)return 0;
    if(dp[sum_price][id][plates] != -1) return dp[sum_price][id][plates]; 
    int r1=-1, r2=-1;  
    r1 = solve(id+1, sum_price, plates);
    if(plates+1 <= 2*(n+1) and sum_price+dimsum[id].first <= money) r2 = solve(id+1, sum_price+dimsum[id].first, plates+1)+dimsum[id].second;   
    return dp[sum_price][id][plates] = max(r1, r2);
}


int main(){
	fastcin	
    cin >> n >> x >> t >> k;

    while(true){
        if(n==0 and x==0 and t==0 and k==0) break;
        memset(dp, -1, sizeof dp);
        for(int i=1; i<=k; i++){
            int sum=0, price;
            cin >> price;
            for(int j=0; j<=n; j++){
                int x;
                cin >> x;
                sum+=x;
            }
            dimsum[i].first = price;
            dimsum[i+k].first = price;
            dimsum[i].second = sum;
            dimsum[i+k].second = sum;
        }
       
        money = floor(double(x * (n+1)) / 1.1 + 1e-6) - (n+1) * t;

        double ans = solve(1,0,0);
        ans/=(n+1.0);
            
        printf("%.2lf\n", ans);
        dimsum.clear();
        cin >> n >> x >> t >> k;
    }
            
	return 0;
}

