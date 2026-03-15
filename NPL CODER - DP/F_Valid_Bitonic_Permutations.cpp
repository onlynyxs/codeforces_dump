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
const ll MOD = 1e9 + 7;
void precompute(int );
void solve();
int main() {
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    
    precompute(100);
    int t=1; 
    cin >> t;
    while (t--) {
        solve();
        // cout << "\n";
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/
vector<ll> fac, ifac;

ll binExp(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

ll modInverse(ll n) {
    return binExp(n, MOD - 2);
}

void precompute(int n) {
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    ifac[n] = modInverse(fac[n]);
    for (int i = n - 1; i >= 0; i--) {
        ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fac[n] * ifac[r]) % MOD) * ifac[n - r]) % MOD;
}

void solve() {
    int n, i, j, x, y;
    if (!(cin >> n >> i >> j >> x >> y)) return;

    if (x > y) {
        i = n - i + 1;
        j = n - j + 1;
        swap(i, j);
        swap(x, y);
    }

    ll count = 0;

    ll sum1 = 0;
    for (int k = i + 1; k < j; k++) {
        sum1 = (sum1 + nCr(n - y - 1, j - k - 1)) % MOD;
    }
    ll part1 = (nCr(x - 1, i - 1) * nCr(y - x - 1, n - j - (x - i))) % MOD;
    count = (count + part1 * sum1) % MOD;

    ll sum2 = 0;
    for (int k = j + 1; k < n; k++) {
        sum2 = (sum2 + nCr(n - y - 1, k - j - 1)) % MOD;
    }
    ll part2 = (nCr(x - 1, i - 1) * nCr(y - x - 1, j - i - 1)) % MOD;
    count = (count + part2 * sum2) % MOD;

    if (y == n) {
        if (j == n) {
            cout << 0 << "\n";
        } else {
            ll res = (nCr(x - 1, i - 1) * nCr(y - x - 1, j - i - 1)) % MOD;
            cout << res << "\n";
        }
        return;
    }

    cout << count << "\n";
}
