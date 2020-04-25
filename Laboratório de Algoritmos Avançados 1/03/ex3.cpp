#include <iostream>
#include <set>
#define ll long long
using namespace std;

int main(){

	int n, x;
	set<ll>s;

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> x;
		s.insert(x);
	}

	cout << s.size() << endl;

	return 0;
}
