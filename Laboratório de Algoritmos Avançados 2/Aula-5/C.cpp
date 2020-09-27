#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define MAX 100010 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int v[MAX];
int n, c, t;

bool check(int m){
    int cnt = 0, cp = 1, sum=0;
    for(int i=0; i<n; i++){
        if(cp > c) return false;
        sum += v[i];
        double q = sum/(double)t;
        if(q > (double)m){
            cp++;
            i--;
            sum = 0;
        }
    }
    
    return true;
}


int main(){
	fastcin	
    cin >> n >> c >> t;
    int l=0, r=0;
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++) r+=v[i];
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }
    cout << l << endl;
	return 0;
}
	

