#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){
    
    fastcin	
    int n;
    cin >> n;
	
    while(true){

        while(true){
            int x;
            stack<int>s, p;
            bool flag = false;
            for(int i=0; i<n; i++){
                cin >> x;
                s.push(x);
                if(x == 0){
                    flag = true;    
                    break;
                }
            }
            if(flag) break;
            int next = n;
            while(!s.empty()){ 
                if(p.empty()){
                    p.push(s.top());
                    s.pop();
                }
                if(next == p.top()){
                    while(!p.empty() and p.top() == next){ 
                        p.pop();
                        next--;
                    }        
                }
                else{
                    p.push(s.top());
                    s.pop();
                }
            }
            
            while(!p.empty() and p.top() == next){ 
                p.pop();
                next--;
            }        
          
            
            if(p.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
            
        }
        
        cin >> n;
           
        cout << endl;
       
        if(n == 0) break;
    }

	return 0;
}
	

