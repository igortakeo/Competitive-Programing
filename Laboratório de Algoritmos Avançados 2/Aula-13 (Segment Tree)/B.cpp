#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f 
#define MAX 4*100001
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int tree[MAX];

struct Range{
    int start = -1;
    int end = -1;
};

int query(int l, int r, int cn, int ra, int rb){
    if(r < ra or l > rb) return -MAX;
    else if(l >= ra and r <= rb) return tree[cn];
    int middle = (l+r)/2;
    return max(query(l, middle, cn*2+1, ra, rb),query(middle+1, r, cn*2+2, ra, rb));
}

//i : index of the value will be updated
//cn : current node in segment tree
//arr[l...r]
void updateValueTree(int l, int r, int i, int new_value, int cn){
    if(l == r and l == i) tree[cn] = new_value;
    else if(i < l || i > r) return;
    else{
        int middle = (l+r)/2;
        updateValueTree(l, middle, i, new_value, 2*cn+1);
        updateValueTree(middle+1, r, i, new_value, 2*cn+2);
        tree[cn] = max(tree[2*cn+1], tree[2*cn+2]);
    }
}

//cn : current node in segment tree
//arr[l...r];
int build(int arr[], int l, int r, int cn){
    if(l == r){
        tree[cn] = arr[l]; 
        return tree[cn];
    }

    int middle = (l+r)/2;
    int left = build(arr, l, middle, 2*cn+1);
    int right = build(arr, middle+1, r, 2*cn+2);
   
    return tree[cn] = max(left, right);
}

int main(){
	fastcin	
    
    int test;
   
    while(true){
        int n, q;
        cin >> n;
        if(n == 0) break;
        cin >> q;

        int arr[n], arr_freq[n];
        map<int, int>freq;
        map<int, Range>start_end;        
        memset(tree, 0, sizeof tree);
        
        for(int i=0; i<n; i++){
            cin >> arr[i];    	
            freq[arr[i]]++;
            if(start_end[arr[i]].start == -1){
                start_end[arr[i]].start = i; 
                start_end[arr[i]].end = i;
            }
            else start_end[arr[i]].end = i;
        }

        for(int i=0; i<n; i++){
           arr_freq[i] = freq[arr[i]];
        }

        build(arr_freq, 0, n-1, 0);

        while(q--){
            int l, r;
            cin >> l >> r;
            l--; r--;
            if(arr[l] == arr[r])
                cout << r-l+1 << endl;
            else{
                int s1 = start_end[arr[l]].end - l + 1;
                int s2 = r - start_end[arr[r]].start + 1;
                int s3 = query(0, n-1, 0, start_end[arr[l]].end+1, start_end[arr[r]].start-1);
                cout << max(s1,max(s2,s3)) << endl;
            }
        }
    
    }

	return 0;
}

