#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int v[MAX];
int cnt;
int tree[4*MAX];
int lazy[4*MAX];

int query(int l, int r, int cn, int ra, int rb){
   	 if(lazy[cn]){ 
        tree[cn] += (l-r+ 1)*lazy[cn];    			
        if(l != r){
            lazy[cn*2+1] += lazy[cn];                 
            lazy[cn*2+2] += lazy[cn];                
        }
        lazy[cn] = 0;                                  
    }
    if(l >= ra and r <= rb) return tree[cn];
    else if(r < ra or l > rb) return 0;
    int middle = (l+r)/2;
    return query(l, middle, cn*2+1, ra, rb) + query(middle+1, r, cn*2+2, ra, rb);
}	

int build(int arr[], int l, int r, int cn){
    if(l == r){
		tree[cn] = arr[l]; 
		if(tree[cn] != 0) cnt++;
		return tree[cn];
	}
    int middle = (l+r)/2;
    int left = build(arr, l, middle, 2*cn+1);
    int right = build(arr, middle+1, r, 2*cn+2);
	if(left+right != 0) cnt++;
	
    return tree[cn] = left + right;
}		
int y = 0;
int solve(int l1, int r1, int l2, int r2, int n){
	y++;
	cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;

	if((l1 == r1 and l2 == r2) or l2>r2 or l1>r1) return 0;
	int f = 0;
	
	for(int i=l1+1; i <= r1; i++){
		for(int j=l2; j<= r2; j++){
			if(query(0, n-1, 0, i, j) != 0) f++;
		}
	}
	for(int j=l2; j<=r2-1; j++){
		if(query(0, n-1, 0, 0, j) != 0) f++;
	}	
	
	
	int middle1 = (l1+r1)/2;
	int middle2 = (l2+r2)/2;
	int a = solve(l1, middle1, middle1+1, r1, n);
	int b = solve(l2, middle2, middle2+1, r2, n);
	
		
	return a+b+f;
}


int main(){

	int n;
	cin >> n;
	
	for(int i =0; i<n; i++) cin >> v[i];
	
	cnt = 0;
		
	build(v, 0, n-1, 0);
	
	int ans = solve(0, (n-1)/2, (n-1)/2+1, n-1, n);
	
	cout << cnt+ans << endl;	

	return 0;
}
