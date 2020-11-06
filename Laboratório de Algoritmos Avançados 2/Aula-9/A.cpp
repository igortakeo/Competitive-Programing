// C++ program for implementation of KMP pattern searching
// algorithm
#include <bits/stdc++.h>
using namespace std;
vector<int>ans;

void computeLPSArray(string pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(string pat, string txt){
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            ans.push_back(i-j+1);
            j = lps[j - 1];
        }

            // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

void computeLPSArray(string pat, int M, int* lps){
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver program to test above function
int main(){
    int n;
    cin >> n;
    while(n--) {
        string txt, pat;
        cin >> txt >> pat;
        KMPSearch(pat, txt);
        if (ans.empty())cout << "Not Found" << endl;
        else {
            cout << ans.size() << endl;
            for (auto a : ans)cout << a << ' ';
            cout << endl;
        }
        cout << endl;
        ans.clear();
    }
    return 0;
}
