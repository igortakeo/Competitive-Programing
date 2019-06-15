#include <bits/stdc++.h>
#define MAX 100001
#define MIN 1
using namespace std;
int n, v[MAX], dp[MAX];

int solve(int u){
    if(v[u]+u == n) return 1;
    if(u >= n) return 0;
    if(dp[u] != 0) return dp[u];
    int sml = MAX;
    for(int i=1; i <= v[u]; i++){
        sml = min(sml, solve(u+i)+1);
        if(sml == MIN) break;
    }
    return dp[u] = sml;
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i < n; i++) cin >> v[i];
    printf("%d\n", solve(1));
    return 0;
}
