#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#define INF 0x3f3f3f3f
#define pis pair<int, string>
#define sc second
#define ft first
using namespace std;

string ed = "12345678x";

int merge_sort(vector<int> &v){
	
	int inv=0;
	
	if(v.size()==1) return 0;
	
	vector<int> u1, u2;
	
	for(int i=0;i<(int)(v.size()/2);i++){
		u1.push_back(v[i]);
	}
	for(int i=(int)(v.size()/2);i<(int)v.size();i++){
	 	u2.push_back(v[i]);
	}	

	inv+=merge_sort(u1);
	inv+=merge_sort(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);
	
	int ini1=0, ini2=0;
	
	for(int i=0;i<(int)v.size();i++){
		if(u1[ini1]<=u2[ini2]){			
			v[i]=u1[ini1];			
			ini1++;
		}
		else{			
			v[i]=u2[ini2];
			ini2++;
			inv+=u1.size()-ini1-1;
		}
	}	
	return inv;
}


int heuristic(string v){
	int cnt=0;
	for(int i=0; i<(int)v.size(); i++){
		if(v[i] == 'x') continue;
		if(v[i] != ed[i])cnt++;
	}
	return cnt;
}

void solve(vector<int>& a){
	string v = "";
	
	for(int i=0; i<(int)a.size(); i++){
		if(a[i] == -1) v+='x';
		else v += a[i] + '0';
	}

	priority_queue<pis, vector<pis>, greater<pis>>pq;
 	unordered_map<string, string> m;
   
	pq.push({0, v});
	m[v]="";

	while(!pq.empty()){
		pis u = pq.top(); 
		pq.pop();


		if(u.sc == ed){
			cout << m[u.sc] << endl;
			return;
		}

		int blank;
		for(int i =0; i<(int)u.sc.size(); i++){
			if(u.sc[i] == 'x'){blank = i; break;}
		}
		string w;

		if(blank != 2 and blank != 5 and blank != 8){
			w = u.sc;
			swap(w[blank], w[blank+1]);
			m[w] += m[u.sc] + 'r';
			pq.push({heuristic(w)+(int)m[w].size(),w});
		}

		if(blank != 0 and blank != 3 and blank != 6){
			w = u.sc;
			swap(w[blank], w[blank-1]);
			m[w] +=  m[u.sc] + 'l';
			pq.push({heuristic(w)+(int)m[w].size(),w});
		}

		if(blank != 0 and blank != 1 and blank != 2){
			w = u.sc;
			swap(w[blank], w[blank-3]);
			m[w] +=  m[u.sc] + 'u';
			pq.push({heuristic(w)+(int)m[w].size(),w});
		}

		if(blank != 6 and blank != 7 and blank != 8){
			w = u.sc;
			swap(w[blank], w[blank+3]);
			m[w] +=  m[u.sc] + 'd';
			pq.push({heuristic(w)+(int)m[w].size(),w});
		}
	
	}

}

int main(){

	int n;
	cin >> n;	

	while(n--){
		cin.ignore();

		vector<int>a(9);
		vector<int>b;
		char s;

		for(int i=0; i<9; i++){
			cin >> s;
			if(s == 'x')a[i] = -1;
			else a[i] = (int)s-'0';
		}
		for(int i=0; i<9; i++){
			if(a[i] == -1) continue;
			b.push_back(a[i]);
		}
		int inv = merge_sort(b);
		
		if(inv%2 != 0){cout << "unsolvable" << endl; continue;}

		solve(a);
		if(n != 0) cout << endl;		
	}



	return 0;
}