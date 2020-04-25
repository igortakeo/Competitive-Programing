
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

int sum, t, n;
set<int>s;
vector<string>d[150];
map<string, bool>vis;
map<int, int>dic;


void combinationUtil(int arr[], int data[], int start, int end, int index, int r) { 
	if (index == r) { 
		for (int j = 0; j < r; j++) sum += data[j];
		if(sum == t){
			string s1;
			for (int j = 0; j < r; j++){
				if(data[j] < 10) s1+='-';
				s1 += to_string(data[j]);
				s1 += '+'; 
			}
			s1.pop_back();
			for(int i=s1.size(); i < 30; i++) s1+='*';
			if(!vis[s1]){
				d[data[0]].push_back(s1);
				vis[s1] = true;
			}	
		} 
		sum = 0;
		return; 
	} 

	for (int i = start; i <= end && end - i + 1 >= r - index; i++) { 
		data[index] = arr[i]; 
		combinationUtil(arr, data, i+1,end, index+1, r); 
	} 
} 

void printCombination(int arr[], int n, int r) { 
	int data[r]; 
	combinationUtil(arr, data, 0, n-1, 0, r); 
} 

int main() { 

	cin >> t >> n;
	
	while(t != 0 and n != 0){
		int v[n];

		for(int i=0; i<n; i++){
			cin >> v[i];	
			s.insert(v[i]);
			dic[v[i]] = i;
		}

		for(int i=1; i<=n; i++) printCombination(v, n, i); 
	
		bool flag = false;
		
		for(auto a : s){
			if(d[a].size() != 0){flag = true; break;}
		}	

		if(flag){	
			cout << "Sums of " << t << ':' << endl;
			for(auto it = s.rbegin(); it != s.rend(); it++){
				int x  = *it;
				sort(d[x].rbegin(), d[x].rend());
				
				for(int j=0; j< (int)d[x].size(); j++){
					int k=0;
					string s2 = d[x][j];
					if(s2[k] == '-') k++;
					while(s2[k] != '*' and k < (int)s2.size()){
						cout << s2[k];
						k++;
						if(s2[k] == '-') k++;
					}
					cout << endl;
				}
				
			}
		}	
		else {
			cout << "Sums of " << t << ':' << endl;
			cout << "NONE" << endl;
		}
		cin >> t >> n;
		s.clear();
		for(int i=0; i<=150; i++) d[i].clear();
		sum = 0;
		vis.clear();
	}


}