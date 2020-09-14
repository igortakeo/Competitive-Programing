#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int t, n, m;
int v[30];
vector<int>ans[50000];
set<vector<int>>ansUnique;

void solve(int u, int sum){	
    if(sum == t){
        ans[m+1] = ans[m];
        ansUnique.insert(ans[m]);
        m++;
        return;        
    }

    for(int i = u; i < n; i++){
        if(sum + v[i] <= t){
            ans[m].push_back(v[i]);
            solve(i+1, sum+v[i]);
            ans[m].pop_back();       
        }
    } 

}

void printans(vector<int>&a){
    cout << a[0];
    for(int i=1; i<a.size(); i++){
        cout << "+" << a[i];
    }
    cout << endl;
}

int main(){
	fastcin	
	while(true){
        cin >> t >> n;

        if(n == 0) break;
    
        for(int i=0; i<n; i++)
            cin >> v[i];
        
        m = 0;
        solve(0,0);

        if(m == 0) cout << "Sums of " << t << ":" << endl <<"NONE" << endl;
        else{
            cout << "Sums of " << t << ":"<< endl;
            for(auto a = ansUnique.rbegin(); a != ansUnique.rend(); a++){
                vector<int> it = *a;
                sort(it.rbegin(), it.rend());
                printans(it);
            }
        }

        for(int it=0; it<m; it++) ans[it].clear();
        memset(v, 0, sizeof v);
        ansUnique.clear();
    }
	return 0;
}
	

