#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define pii pair<int,int>
using namespace std;

vector<tuple<int, int, int>>v;

vector<int> lis(int n){
	
	vector<pii>dp[n];
	vector<int>ans;
	
	dp[0].push_back({get<1>(v[0]), get<2>(v[0])});
	
	for(int i=1; i<n; i++){
		for(int j=0; j < i; j++){
			if(get<1>(v[i]) > get<1>(v[j]) and dp[i].size() < dp[j].size() + 1 and get<0>(v[i]) < get<0>(v[j])){
				dp[i] = dp[j];
			}
		}
		dp[i].push_back({get<1>(v[i]), get<2>(v[i])});
	}
	
	int m = 0;
	for(int i=1; i<n; i++){
		if(dp[i].size() > dp[m].size())m=i;
	}
	
	for(auto a : dp[m])ans.push_back(a.second);
	
	return ans;
}

int main(){
	
	int x, y;
	int i=1;
	while(scanf("%d %d",&x, &y) != EOF){
		v.push_back(make_tuple(x, y, i));
		i++;
	}
	
	sort(v.rbegin(), v.rend());
	
	vector<int> ans = lis(i-1);
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for(auto a: ans) cout << a << endl;
	
	return 0;
}
