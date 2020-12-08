#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f 
#define MAX 4*100001
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int tree[MAX];

int query(int l, int r, int cn, int ra, int rb){
    if(l >= ra and r <= rb) return tree[cn];
    else if(r < ra or l > rb) return 1;
    int middle = (l+r)/2;
    return query(l, middle, cn*2+1, ra, rb) * query(middle+1, r, cn*2+2, ra, rb);
}

//i : index of the value will be updated
//cn : current node in segment tree
//diff : new_value - old_value
//arr[l...r]
void updateValue(int l, int r, int i, int new_value, int cn){
    if(l == r and l == i) tree[cn] = new_value;
    else if(i < l || i > r) return;
    else{
        int middle = (l+r)/2;
        updateValue(l, middle, i, new_value, 2*cn+1);
        updateValue(middle+1, r, i, new_value, 2*cn+2);
        tree[cn] = tree[2*cn+1] * tree[2*cn+2];
    }
}

//cn : current node in segment tree
//arr[l...r];
int build(int arr[], int l, int r, int cn){
    if(l == r){tree[cn] = arr[l]; return tree[cn];}
    int middle = (l+r)/2;
    int left = build(arr, l, middle, 2*cn+1);
    int right = build(arr, middle+1, r, 2*cn+2);

    return tree[cn] = left * right;
}


int main(){
    
    int n, k;

    while(cin >> n >> k){
        
        string ans = "";
        int v[n];
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(v[i] > 0) v[i] = 1;
            else if(v[i] < 0) v[i] = -1;
        }
        
        build(v, 0, n-1, 0); 

        while(k--){
            char c;
            int x, y;
            cin >> c >> x >> y;
             
            if(c == 'C'){
                if(y != 0) y = (y > 0) ? 1 : -1;
                updateValue(0, n-1, x-1, y, 0);       
            }
            else{
                int r = query(0, n-1, 0, x-1, y-1);
                if(r < 0) ans+='-';
                else if(r > 0) ans+='+';
                else ans+='0';
            }
        }
        cout << ans << endl;
        memset(tree, 0, sizeof tree);
    }
    
   

    return 0;
}





