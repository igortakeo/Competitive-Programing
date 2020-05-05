#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){

		int a, b, c, d;
		int x,y,x1,y1,x2,y2;

		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		int z = a-b;
		int w = c-d;

		if(a==0 and b==0 and c==0 and d == 0) cout << "YES" << endl;
		else if(z == 0 or w == 0){

			if(z == 0 and w ==0){
				if(((x-x1 != 0 or x-x2 != 0) or (a==0 and b==0)) and ((y-y1 != 0 or y-y2 != 0) or (c==0 and d==0))) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else if(z != 0 and w == 0){
				if(((y-y1 != 0 or y-y2 != 0) or (c==0 and d==0)) and ((z > 0 and x-z >= x1) or (z < 0 and x-z <= x2))) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else if(z == 0 and w != 0){
				if(((x-x1 != 0 or x-x2 != 0) or (a == 0 and b == 0)) and ((w > 0 and y-w >= y1) or (w < 0 and y-w <= y2))) cout << "YES" << endl;
				else cout << "NO" << endl;	
			}

		}
		else{
			if((z > 0 and w > 0 and x-z >= x1 and y-w >= y1) or (z > 0 and w < 0 and  x-z >= x1 and y-w <= y2) or (z < 0 and w < 0 and  x-z <= x2 and y-w <= y2) or (z < 0 and w > 0 and  x-z <= x2 and y-w >= y1)) cout << "YES" << endl; 
			else cout << "NO" << endl;
		}
	}



	return 0;
}