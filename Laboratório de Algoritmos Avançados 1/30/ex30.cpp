#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <math.h>
#define inf 1e9
using namespace std ;

map<pair<char, char>,int>score;
map<pair<int, int>,int>dp;
map<pair<int, int>, bool>vis;
map<pair<int, int> ,bool>backvis;
string s, t;
int n, ans, cnt=0;

int solve(int i, int j){
	
	if(i >=(int)s.size() or j >= (int)t.size() or i==-1 or j==-1) return 0;
	
	if(i < -1 or j < -1) return inf;
	if(vis[make_pair(i,j)]){
		return dp[make_pair(i,j)];
	}
	int ret = inf;
	
	if(i < (int)s.size() and j<(int)t.size()){
		ret = solve(i-1, j-1)+score[make_pair(s[i], t[j])];
	}
	
	dp[make_pair(i,j)] = min(solve(i-1, j)+3, min(solve(i, j-1)+3, ret));
	
	vis[make_pair(i,j)] = true;
	if(i == j and !backvis[make_pair(i,j)]){
		ans = max(ans, dp[make_pair(i,j)]);
		backvis[make_pair(i,j)] = true;
	}
	
	return dp[make_pair(i,j)] + solve(i+1, j+1);	
}


int main(){
	
	char letters[5] = {'A', 'G', 'C', 'T', '-'};
	
	for(int i=0; i<4; i++) score[make_pair(letters[i], letters[i])]=0;
	for(int i=1; i<4; i++){
		score[make_pair('A', letters[i])] = 5;
		score[make_pair(letters[i], 'A')] = 5;
	}
	for(int i=1; i<3; i++){
		score[make_pair(letters[i], 'T')] = 5;
		score[make_pair(letters[i], 'T')] = 5;
	}
	for(int i=0; i<4; i++){
		score[make_pair('-', letters[i])] = 3;
		score[make_pair(letters[i], '-')] = 3;
	}
	score[make_pair('G', 'C')] = 4;
	score[make_pair('C', 'G')] = 4;
	
	while(cin >> s  and cin >> t){
		dp[make_pair(-1,-1)] = 0;
		vis[make_pair(-1,-1)] = true;
		ans = 0;
		solve(0,0);
		int diff = abs((int)s.size()-(int)t.size());
		if(diff > 1 or diff == 0)cout << ans+(diff > 0)+diff*3<< endl;
		else cout << ans+1 <<endl;
		dp.clear();
		vis.clear();
		backvis.clear();
	} 
	return 0;
}
