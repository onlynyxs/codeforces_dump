#include <bits/stdc++.h>
using namespace std;
/*---------------------Boring-stuff----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
typedef __int128_t int128;
const int MAX_N = 1e5 + 5;
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

bool is_bad(ll y) {
    if (y % 7 != 0) return false;
    ll s7 = 7, s6 = 6;
    while (y % s7 == 0) {
        if (y % (s7 * s6) != 0) return true;
        if (s7 > 2e18 / 7 || s6 > 2e18 / 6) break;
        s7 *= 7; s6 *= 6;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll rem = a[0] % 6;
    for (int i = 1; i < n; ++i) {
        if (a[i] % 6 != rem) { cout << -1; return; }
    }

    ll x0 = (6 - rem) % 6;
    vector<ll> c;
    for (int i = 0; i < n; ++i) c.push_back((a[i] + x0) / 6);
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    vector<ll> candidates;
    for (int m = 0; m < 42; ++m) {
        bool ok = true;
        for (ll ci : c) {
            if (is_bad(ci + m)) { ok = false; break; }
        }
        if (ok) candidates.push_back(m);
    }

    ll P = 42;
    for (int k = 2; k <= 6; ++k) {
        if (candidates.empty()) break;
        vector<ll> next_candidates;
        for (ll m : candidates) {
            for (int j = 0; j < 42; ++j) {
                ll m_prime = m + (ll)j * P;
                bool ok = true;
                for (ll ci : c) {
                    if (is_bad(ci + m_prime)) { ok = false; break; }
                }
                if (ok) {
                    next_candidates.push_back(m_prime);
                    if (next_candidates.size() > 500) break; 
                }
            }
            if (next_candidates.size() > 500) break;
        }
        candidates = next_candidates;
        P *= 42;
        if (P > 1e12) break;
    }

    if (candidates.empty()) cout << -1;
    else {
        sort(candidates.begin(), candidates.end());
        cout << 6 * candidates[0] + x0;
    }
}