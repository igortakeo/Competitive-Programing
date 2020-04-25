#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

vector<string>rules;
set<string>ans;
int pt, al;
bool f5;

void CombinationRepetitionUtil(int chosen[], string arr[],int index, int r, int start, int end) { 
    if (index == r) { 
    	
        bool flag = true;
        int c;
        for (int i = 0; i < r; i++){
        	if(rules[pt][i] == '#'){
        		c = (int)arr[chosen[i]][0];
        		if((int)arr[chosen[i]].size() == 1 and (c >= 48 and c <= 57)) flag=false;
        	}
        	else{
        		c = (int)arr[chosen[i]][0];
        		if((int)arr[chosen[i]].size() > 1 or (c < 48 or c > 57)) flag = false;
        	}

        	if(!flag) break;
        } 
		
        if(flag){
        	string s1;
        	for(int i = 0; i < r; i++){
        		c = (int)arr[chosen[i]][0];
        		if(c >= 48 and c <= 57) s1+="~"; 
        		if((int)arr[chosen[i]].size() > 1){
    				for(int j=0; j<al; j++)s1+= "~";
        		}
        		s1 += arr[chosen[i]];
        	}
        	ans.insert(s1);
        }

        flag = false;

        while(next_permutation(chosen, chosen+r) and !flag){
        	
        	flag = true;
	        for (int i = 0; i < r; i++){
	        	if(rules[pt][i] == '#'){
	        		c = (int)arr[chosen[i]][0];
	        		if((int)arr[chosen[i]].size() == 1 and (c >= 48 and c <= 57)) flag=false;
	        	}
	        	else{
	        		c = (int)arr[chosen[i]][0];
	        		if((int)arr[chosen[i]].size() > 1 or (c < 48 or c > 57)) flag = false;
	        	}

	        	if(!flag) break;
	        }
	        
	        if(flag){
	        	string s2;
	        	for(int i = 0; i < r; i++){
	        		c = (int)arr[chosen[i]][0];
        			if(c >= 48 and c <= 57) s2+="~";
        			if((int)arr[chosen[i]].size() > 1){
        				for(int j=0; j<al; j++)s2+= "~";
        			} 
	        		s2+= arr[chosen[i]];
	        	}    	
	        	ans.insert(s2);
	        }
	        flag = false;
	    }

        return; 
    } 
    for (int i = start; i <= end; i++) { 
        chosen[index] = i; 
        CombinationRepetitionUtil(chosen, arr, index + 1, r, i, end); 
    } 
    return; 
} 
  
void CombinationRepetition(string arr[], int n, int r) { 
    int chosen[r+1]; 
    CombinationRepetitionUtil(chosen, arr, 0, r, 0, n-1); 
} 

int main(){

	int n;

	while(scanf("%d", &n) != EOF){
		int m;	
		string s;		
		vector<string>v; 
		string arr[11] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "*"};

		for(int i=0; i<n; i++){
			cin >> s;
			v.push_back(s);
		}

		cin >> m;

		for(int i=0; i<m; i++){
			cin >> s;
			rules.push_back(s);
		}

		cout << "--" << endl;

		for(int i=0; i<m; i++){
			pt = i;
			int r = (int)rules[i].size();
			for(int j=0; j<n; j++){
				al = j;
				arr[10] = v[j];
				CombinationRepetition(arr, 11, r); 
				arr[10] = "*";
			}
			
			for(auto a : ans){
				string s3 = a;
				for(int i=0; i<(int)s3.size(); i++){
					if(s3[i] == '~') continue;
					cout << s3[i];
				}
				cout << endl;
			}
			
			ans.clear();
		}

		rules.clear();
		ans.clear();
	}


	return 0;
}