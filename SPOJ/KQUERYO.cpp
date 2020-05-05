#include <bits/stdc++.h>
#define N 100005
#define all(v) v.begin(), v.end()
using namespace std;

vector<int> tree[4*N];

void build(int arr[], int l, int r, int cn) { 
  
    if (l == r){ 
        tree[cn].push_back(arr[l]); 
        return; 
    } 
  
    int mid = (l + r)/2; 
    build(arr,l,mid,2*cn+1); 
    
    build(arr,mid+1,r,2*cn+2); 
  
	merge(all(tree[2*cn+1]), all(tree[2*cn+2]), back_inserter(tree[cn]));
 } 	
  
int query(int l, int r, int lb, int rb, int k, int cn) { 
  
    if (l >= lb && r <= rb) { 
        return tree[cn].size() - (upper_bound(all(tree[cn]), k) - tree[cn].begin()); 
    } 	
    else if(r < lb or l > rb) return 0;
  
    int mid = (l+r)/2; 
    return (query(l, mid, lb, rb, k, 2*cn+1) + query(mid+1, r, lb, rb, k, 2*cn+2)); 
}   
  
int main(){
	
	int n;
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; i++) cin >> arr[i];
	
	build(arr, 0, n-1, 0);
	
	int q, last_ans=0;
	cin >> q;
	
	while(q--){
		int i, j, k;
		cin >> i >> j >> k;
		
		
		i = i xor last_ans;
	    j = j xor last_ans;
		k = k xor last_ans;	
			
		
		if(i < 1) i = 1;
		if(j > n) j = n;
		
		
		if(i > j){
			cout << 0 << endl;
			last_ans = 0;
		}
		else{
			last_ans = query(0, n-1, i-1, j-1, k, 0);
			cout << last_ans << endl;		
		}
	}
		
	return 0;
}
