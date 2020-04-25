#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int board[9][9], startboard[8]; 
vector<int>v;
set<vector<int>>s;

void solve(int row, int column){

	if(column > 8){
		s.insert(v);
		return;
	}
	bool flag = false;
	
	for(int k=1; k<=8; k++){
		if(board[row][k] == 1) flag = true;
	}
	
	for(int k = column-1; k>=1; k--){
		if(board[row][k] == 1) flag = true;
	}
	
	int i=row, j=column;
	while(i <= 8 and j<= 8){
		if(board[i][j] == 1) flag = true;
		i++; j++;
	} 
	i = row; j = column;
	while(i >= 1 and j >= 1){
		if(board[i][j] == 1) flag = true;
		i--; j--;
	}
	i = row; j = column;
	while(i >= 1 and j <= 8){
		if(board[i][j] == 1) flag = true;
		i--; j++;
	}
	i = row; j = column;
	while(i <= 8 and j >= 1){
		if(board[i][j] == 1) flag = true;
		i++; j--;
	}

	if(!flag){
		board[row][column] = 1;
		v.push_back(row);
		solve(1, column+1);
		board[row][column] = 0;	
		v.pop_back();
	}
	for(int i=row+1; i<=8; i++) return solve(i, column);
}

int main(){	
	int cnt = 1;
	solve(1,1);

	while(scanf("%d %d %d %d %d %d %d %d", 
		&startboard[0], &startboard[1], &startboard[2], &startboard[3], &startboard[4], &startboard[5], &startboard[6], &startboard[7]) != EOF){

		int ans=8, diff, b=0;
	
		for(auto a : s){
			b = 0;
			for(int i=0; i<(int)a.size(); i++){
				diff = abs(startboard[i] - a[i]);
				if(diff > 0) b++;
			}
			ans = min(b, ans);
		}
		cout << "Case " << cnt << ": ";
		cout << ans << endl;

		cnt++;
	}
	

	return 0;
}