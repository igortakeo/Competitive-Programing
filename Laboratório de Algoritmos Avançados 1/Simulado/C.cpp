#include <bits/stdc++.h>
using namespace std;

#define MAXN 10100
#define MAXS 10100

int n, valor[MAXN];	

vector<int>path;
map<int, vector<int>>m;
set<int>st;

void solve(int sum, int i){
	
	m[sum] = path;
	st.insert(sum);

	if(i == n)return;
	
	for(int j=i; j<n; j++){	
		path.push_back(valor[j]);	
		sum+=valor[j];
		solve(sum, j+1);
		sum-=valor[j];			
		path.pop_back();
	}

}

int main(){

	int aguenta;

	while(scanf("%d", &aguenta) != EOF){
		cin >> n;

		for(int i=0; i<n; i++) cin >> valor[i];

		solve(0, 0);	

		auto a = lower_bound(st.begin(), st.end(), aguenta); 
		if(*a > aguenta)a--;
		

		while(m[*a].size() == 0)a--;

		for(auto it : m[*a]) cout << it << ' ';

		cout << "sum:" << *a << endl;

		m.clear();
	}


}	