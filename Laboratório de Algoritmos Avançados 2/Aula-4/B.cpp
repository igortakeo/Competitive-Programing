#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sd second
#define ft first
using namespace std;

map<string, tuple<string, int, bool>>m;
queue<string>q;
int cnt = 0;

void solve(string s, int blank){
    
	if(blank != 2 and blank != 5 and blank != 8){
		string v = s;
        swap(v[blank], v[blank+1]);
        if(m.find(v) == m.end()){
            q.push(v);
            m[v] = make_tuple(get<0>(m[s])+"r", blank+1, false);
        }
	}

	if(blank != 0 and blank != 3 and blank != 6){
		string v = s;
        swap(v[blank], v[blank-1]);
		if(m.find(v) == m.end()){
            q.push(v);
            m[v] = make_tuple(get<0>(m[s])+"l", blank-1, false);	
	    }
    }

	if(blank != 0 and blank != 1 and blank != 2){
		string v = s;
        swap(v[blank], v[blank-3]);
		if(m.find(v) == m.end()){
            q.push(v);
            m[v] = make_tuple(get<0>(m[s])+"u", blank-3, false);
	    }
    }

	if(blank != 6 and blank != 7 and blank != 8){
		string v = s;
        swap(v[blank], v[blank+3]);
		if(m.find(v) == m.end()){
            q.push(v);
            m[v] = make_tuple(get<0>(m[s])+"d", blank+3, false);
	    }
    }

}


int main(){
    
	string s = "12345678x";
    q.push(s);
    m[s] = make_tuple("", 8, false);

    while(!q.empty()){
        string x = q.front();
        q.pop(); 
        solve(x, get<1>(m[x])); 
    }
    
    int n;
	cin >> n;	

	while(n--){
		cin.ignore();

		char c;
		string a = "";

		for(int i=0;i<9; i++){
			cin >> c;
			a+=c;
		}

		if(m.find(a) == m.end())
			cout << "unsolvable" << endl;
		else{
            string ans = get<0>(m[a]);
            reverse(ans.begin(), ans.end());
            for(int i=0; i<ans.size(); i++){
                if(ans[i] == 'r') ans[i] = 'l';
                else if(ans[i] == 'l') ans[i] = 'r';
                else if(ans[i] == 'u') ans[i] = 'd';
                else ans[i] = 'u'; 
            }
			cout << ans << endl;				
		}

		if(n != 0) cout << endl;		
	}


	return 0;
}
