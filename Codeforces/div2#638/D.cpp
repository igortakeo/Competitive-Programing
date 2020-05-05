#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
		
	int t;
	cin >> t;
	
	while(t--){
		
		ll n, ans, ansp=0;
		cin >> n;
		
		ans = n-1;
		vector<int> a[31];
		
		for(int i=0; i<=30; i++){
			if(1<<i == n){
				for(int j=0; j<i; j++)a[0].push_back(j);
				ans = a[0].size();
				break;
			}
		}
		
		if(a[0].size() == 0){
			for(int i=0; i<n; i++) a[0].push_back(0);
		}
		
		
		int j=1, k;
		double u;
		bool flag;
		while(1<<j < n){
			flag = true;
			double d = n/(double)(1<<j);	
			int e = (int)d;
			double f = d-e;
			
			printf("%d %lf %d %lf\n", j, d, e, f);
			
			if(f == 0.5){
				a[j].push_back(1);
				for(int i=0; i<e-1; i++)a[j].push_back(0);
			}
			else if(f > 0.5){
				k = 2;
				a[j].push_back(1);
				a[j].push_back(2);	
				u = 1.75;
				
				while(u-1 < f and k <= 30){
					a[j].push_back(1<<k);	
					k++;
					u = u/2 + 1;
				}
				
				if(u-1 == f){
					for(int i=0; i<e-1; i++)a[j].push_back(0);
				}
				else flag = false;
			}
			else if(f < 0.5){
				k = 2;
				a[j].push_back(1);
				a[j].push_back(0);
				a[j].push_back(2);	
				u = 2.25;
				
				while(u-2 > f and k<=30){
					a[j].push_back(1<<k);	
					k++;
					u = u/2 + 1;
				}
				
				if(u-2 == f){
					for(int i=0; i<e-2; i++)a[j].push_back(0);
				}
				else flag = false;	
			}
			
			if(flag){
				if(ans > a[j].size()){
					ans = a[j].size();
					ansp = j;
				}
			}
			j++;
		}
		
		cout << ans << endl;
		for(auto it : a[ansp])cout << it << ' ';
		cout << endl;
		
	}	
		
	      
	return 0;
}

