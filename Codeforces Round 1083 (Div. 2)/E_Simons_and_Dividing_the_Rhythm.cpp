#include <bits/stdc++.h>
using namespace std;
/*---------------------Boring-stuff----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
const int MAX_N = 1e5 + 5;
const int MOD = 998244353;
void solve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    int t=1; 
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    vector<int> pi(n);

    for (int l = 0; l < n; ++l) {
        if (dp[l] == 0) continue;

        dp[l + 1] = (dp[l + 1] + dp[l]) % MOD;

        pi[0] = 0; 
        int m = n - l;
        for (int i = 1; i < m; ++i) {
            int j = pi[i - 1];
            while (j > 0 && t[l + i] != t[l + j]) j = pi[j - 1];
            if (t[l + i] == t[l + j]) j++;
            pi[i] = j;

            if (pi[i] == 0) {
                dp[l + i + 1] = (dp[l + i + 1] + dp[l]) % MOD;
            }
        }
    }

    cout << dp[n] ;
}