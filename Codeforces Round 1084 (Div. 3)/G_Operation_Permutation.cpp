#include <bits/stdc++.h>
using namespace std;
/*---------------------Boring-stuff----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
const int MAX_N = 3005; 
const ll MOD = 1e9 + 7;
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

ll power(ll base, ll exp) {
    ll res = 1;
    base %= 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, 1000000007 - 2);
}

ll fact[MAX_N], invFact[MAX_N];
bool precomputed = false;

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAX_N - 1] = modInverse(fact[MAX_N - 1]);
    for (int i = MAX_N - 2; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    precomputed = true;
}

ll nCr_inv(int n_val, int r_val) {
    if (r_val < 0 || r_val > n_val) return 0;
    return (((invFact[n_val] * fact[r_val]) % MOD) * fact[n_val - r_val]) % MOD;
}

void solve() {
    precompute();
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<ll, ll>> ops(n);
    ll total_a_prod = 1;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        char type = s[0];
        ll y = stoll(s.substr(1));

        if (type == '+') {
            ops[i] = {1, y % MOD};
        } else if (type == '-') {
            ops[i] = {1, (MOD - (y % MOD)) % MOD};
        } else if (type == 'x') {
            ops[i] = {y % MOD, 0};
        } else if (type == '/') {
            ops[i] = {modInverse(y % MOD), 0};
        }
        total_a_prod = (total_a_prod * ops[i].first) % MOD;
    }

    vector<ll> c(n + 1, 0);
    c[0] = 1;
    for (int i = 0; i < n; ++i) {
        ll ai = ops[i].first;
        for (int j = i + 1; j >= 1; --j) {
            c[j] = (c[j] * ai + c[j - 1]) % MOD;
        }
        c[0] = (c[0] * ai) % MOD;
    }

    ll expected_b_sum = 0;
    ll inv_n = modInverse(n);

    for (int i = 0; i < n; ++i) {
        if (ops[i].second == 0) continue;

        ll ai = ops[i].first;
        ll bi = ops[i].second;

        vector<ll> d(n);
        d[n - 1] = c[n];
        for (int j = n - 2; j >= 0; --j) {
            d[j] = (c[j + 1] - (d[j + 1] * ai) % MOD + MOD) % MOD;
        }

        ll poly_sum = 0;
        for (int j = 0; j < n; ++j) {
            ll ej = d[n - 1 - j];
            poly_sum = (poly_sum + ej * nCr_inv(n - 1, j)) % MOD;
        }

        ll contrib = (((bi * inv_n) % MOD) * poly_sum) % MOD;
        expected_b_sum = (expected_b_sum + contrib) % MOD;
    }

    ll ans = ((x % MOD * total_a_prod) % MOD + expected_b_sum) % MOD;
    cout << ans;
}