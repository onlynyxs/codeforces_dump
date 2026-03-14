/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
 |   Competitive Programming Template                   |
 |   Author: Nyxs                                       |
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <bits/stdc++.h>
using namespace std;
/*---------------------Niche Things----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
#define inp(n) for(int i=0;i<n ;i++)
const int MAX_N = 1e5 + 5;
const ll MOD = 998244353;

void solve();
int main() {
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    
    
    int t=1; 
    // cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n, k, len;
    cin >> n >> k >> len;

    if (len == 1) {
        cout << 0;
        return;
    }

    vector<int> a(n + 1);
    vector<vector<int>> can(n + 1, vector<int>(k + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= k; ++j) {
            if (a[i] == -1 || a[i] == j) {
                can[i][j] = can[i - 1][j] + 1;
            } else {
                can[i][j] = 0;
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    vector<int> sum_dp(n + 1, 0);

    sum_dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (a[i] != -1 && a[i] != j) continue;

            dp[i][j] = sum_dp[i - 1];

            if (i >= len && can[i][j] >= len) {
                int invalid = (sum_dp[i - len] - dp[i - len][j] + MOD) % MOD;
                
                if (i == len) invalid = 1;
                
                dp[i][j] = (dp[i][j] - invalid + MOD) % MOD;
            }
            sum_dp[i] = (sum_dp[i] + dp[i][j]) % MOD;
        }
    }

    cout << sum_dp[n];
}