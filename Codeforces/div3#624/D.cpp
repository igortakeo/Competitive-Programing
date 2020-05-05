#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct node{
	int a,b,c;
};

vector<int> v[11010];
vector<node> ans;

int main(){

	fastcin
	
	for(int i=1;i<=11000;i++){
		for(int j=1;j<=sqrt(i);j++){
			if(i%j==0) {
				if(i!=j*j) v[i].push_back(j);
				v[i].push_back(i/j);
			}
		}
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[v[i][j]].size();k++){
				ans.push_back(node{v[v[i][j]][k],v[i][j],i});
			}
		}
	}
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++){
		printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
	}
	
	      
	return 0;
}

