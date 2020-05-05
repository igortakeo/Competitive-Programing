#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000005
using namespace std;


int tree[4*MAX];
int lazy[4*MAX];

int query(int l, int r, int cn, int ra, int rb){
   	 if(lazy[cn] != 0){ 
        tree[cn] += lazy[cn];    				
        if(l != r){
            lazy[cn*2+1] += lazy[cn];                
            lazy[cn*2+2] += lazy[cn];                
        }
        lazy[cn] = 0;                                  
    }
    if(l >= ra and r <= rb) return tree[cn];
    else if(r < ra or l > rb) return MAX;
    int middle = (l+r)/2;
    return min(query(l, middle, cn*2+1, ra, rb), query(middle+1, r, cn*2+2, ra, rb));
}

void updateValue(int l, int r, int a, int b, int new_value, int cn){
	 if(lazy[cn] != 0){ 
        tree[cn] += lazy[cn];    			
        if(l != r){
            lazy[cn*2+1] += lazy[cn];                
            lazy[cn*2+2] += lazy[cn];                
        }
        lazy[cn] = 0;                                 
    }
    if(l > b or r < a) return;
    else if(a <= l and r <= b){
		tree[cn] += new_value;
        if(l != r){
            lazy[cn*2+1] += new_value;                 
            lazy[cn*2+2] += new_value;                
        }
    }
    else{
        int middle = (l+r)/2;
        updateValue(l, middle, a, b, new_value, 2*cn+1);
        updateValue(middle+1, r, a, b, new_value, 2*cn+2);
        tree[cn] = min(tree[2*cn+1],tree[2*cn+2]);
    }
}

int build(int arr[], int l, int r, int cn){
    if(l == r){tree[cn] = arr[l]; return tree[cn];}
    int middle = (l+r)/2;
    int left = build(arr, l, middle, 2*cn+1);
    int right = build(arr, middle+1, r, 2*cn+2);

    return tree[cn] = min(left , right);
}

int main(){

	fastcin
	
	int n;
	cin >> n;
	
	string s;	
	cin >> s;
	
	int sum[n], ans=0;
	
	if(s[0] == '(') sum[0] = 1;
	else sum[0] = -1;
	
	for(int i=1; i<n; i++){
		if(s[i] == '(') sum[i] = sum[i-1]+1;
		else sum[i] = sum[i-1]-1;
	}
	
	build(sum, 0, n-1, 0);
	
	for(int i=0; i<n; i++){
		
		if(s[i] == '('){
			updateValue(0, n-1, i, n-1, -2, 0);
			if(query(0, n-1, 0, 0, n-1) == 0 and query(0, n-1, 0, n-1, n-1) == 0) ans++;
			updateValue(0, n-1, i, n-1, 2, 0);
		}
		else{
			updateValue(0, n-1, i, n-1, 2, 0);
			if(query(0, n-1, 0, 0, n-1) == 0 and query(0, n-1, 0, n-1, n-1) == 0) ans++;
			updateValue(0, n-1, i, n-1, -2, 0);
		}
	
	}
	
	cout << ans << endl;	
		
	return 0;
}
