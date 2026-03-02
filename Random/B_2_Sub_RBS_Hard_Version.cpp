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
const ll MOD = 998244353;
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
    string s;
    cin >> s;

    vector<vector<ll>> dp_tot(n + 1, vector<ll>(n + 1, 0));
    vector<vector<vector<ll>>> dp_bad(n + 1, vector<vector<ll>>(n + 1, vector<ll>(4, 0)));

    dp_tot[0][0] = 1;
    dp_bad[0][0][0] = 1;

    for (char c : s) {
        vector<vector<ll>> next_tot = dp_tot;
        vector<vector<vector<ll>>> next_bad = dp_bad;

        for (int l = 0; l < n; ++l) {
            for (int b = 0; b <= l; ++b) {
                if (dp_tot[l][b] > 0) {
                    if (c == '(') {
                        next_tot[l + 1][b + 1] = (next_tot[l + 1][b + 1] + dp_tot[l][b]) % MOD;
                    } else if (b > 0) {
                        next_tot[l + 1][b - 1] = (next_tot[l + 1][b - 1] + dp_tot[l][b]) % MOD;
                    }
                }

                for (int st = 0; st < 4; ++st) {
                    if (dp_bad[l][b][st] == 0) continue;
                    ll val = dp_bad[l][b][st];

                    if (c == '(') {
                        if (st == 0) next_bad[l + 1][b + 1][0] = (next_bad[l + 1][b + 1][0] + val) % MOD;
                        if (st == 1) next_bad[l + 1][b][2] = (next_bad[l + 1][b][2] + val) % MOD;
                    } else { 
                        if (st == 0 && b > 0) next_bad[l + 1][b - 1][1] = (next_bad[l + 1][b - 1][1] + val) % MOD;
                        if (st == 1 && b > 0) next_bad[l + 1][b - 1][1] = (next_bad[l + 1][b - 1][1] + val) % MOD;
                        if (st == 2) next_bad[l + 1][b][3] = (next_bad[l + 1][b][3] + val) % MOD;
                        if (st == 3 && b > 0) next_bad[l + 1][b - 1][3] = (next_bad[l + 1][b - 1][3] + val) % MOD;
                    }
                }
            }
        }
        dp_tot = next_tot;
        dp_bad = next_bad;
    }

    ll ans = 0;
    for (int k = 1; k <= n / 2; ++k) {
        ll total = dp_tot[2 * k][0];
        ll bad = (dp_bad[2 * k][0][1] + dp_bad[2 * k][0][3]) % MOD;
        ll score_len = (2LL * k - 2 + MOD) % MOD;
        ans = (ans + (total - bad + MOD) % MOD * score_len) % MOD;
    }

    cout << ans ;
}