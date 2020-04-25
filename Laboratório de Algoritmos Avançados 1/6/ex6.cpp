#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int main(){

    int n;

    while(scanf("%d", &n) != EOF){

        queue<int>q;
        stack<int>s;
        priority_queue<int>pq;

        bool f1=true, f2=true, f3=true;
        int x, y;

        for(int i=0; i< n; i++){
            cin >> x >> y;
            if(x == 1){
                q.push(y);
                s.push(y);
                pq.push(y);
            }
            else{
               if(q.empty() or q.front() != y) f1 = false; 
               if(s.empty() or s.top() != y) f2 = false; 
               if(pq.empty() or pq.top()!= y) f3 = false; 

               if(!q.empty()) q.pop();
               if(!s.empty())s.pop();
               if(!pq.empty()) pq.pop();
            }
        }

        if((f1 and f2 and f3) or (f1 and f2) or (f1 and f3) or (f2 and f3)) cout << "not sure" << endl;
        else if(f1) cout << "queue"<< endl;  
        else if(f2) cout << "stack" << endl;
        else if(f3) cout << "priority queue" << endl;
        else cout << "impossible" << endl;
    }

    return 0;
}