#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define MAXN 1001 
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// declaro as variáveis que vou usar
string s1, s2;
int tab[MAXN][MAXN];

int lcs(int a, int b){ // declaro a função da DP, de nome lcs
    //cout << s1 << ' ' << s2 << endl;	
	// se já calculamos esse estado da dp antes
	if(a >= 0 and b >= 0 and tab[a][b] >= 0) return tab[a][b]; // retornamos o valor salvo para ele
	
	// se uma das sequências for vazia, retornamos zero
	if(a==-1 or b==-1) return 0;
	
	// se s1[a] for igual a s2[b], os retiramos das sequências
	if(s1[a]==s2[b]) return 1+lcs(a-1, b-1); // e adicionamos ele à lcs das subsequencias restantes
	
	// se forem diferentes, retorno o máximo entre retirar s1[a] ou s1[b]
	return tab[a][b]=max(lcs(a-1, b), lcs(a, b-1));
}

int main(){
	fastcin	
	
    while(getline(cin,s1)){
        getline(cin, s2);
        memset(tab, -1, sizeof tab);
        int ans = lcs(s1.size()-1,s2.size()-1);
        cout << ans << endl;
    }

	return 0;
}

