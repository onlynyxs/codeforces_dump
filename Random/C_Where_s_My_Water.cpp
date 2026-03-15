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

void solve();
int main() {
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    
    
    int t=1; 
    cin >> t;
    while (t--) {
        solve();
        // cout << "\n";
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n; ll h;
    cin >> n >> h;
    vector<ll> a(n);
    vector<ll> vals;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < h) vals.push_back(a[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int K = vals.size();
    if (K == 0) { cout << 0 << "\n"; return; }

    vector<vector<int>> W(n, vector<int>(K, 0));
    for (int k = 0; k < K; ++k) {
        ll H = vals[k] + 1;
        for (int i = 0; i < n; ) {
            if (a[i] < H) {
                int j = i;
                while (j < n && a[j] < H) j++;
                for (int m = i; m < j; ++m) W[m][k] = j - i;
                i = j;
            } else i++;
        }
    }

    vector<vector<ll>> G(n, vector<ll>(K, 0));
    for (int i = 0; i < n; ++i) {
        ll current_sum = 0;
        for (int k = K - 1; k >= 0; --k) {
            ll span = (k == K - 1) ? (h - vals[k]) : (vals[k + 1] - vals[k]);
            current_sum += (ll)W[i][k] * span;
            G[i][k] = current_sum;
        }
    }

    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        M[i][i] = (int)a[i];
        for (int j = i + 1; j < n; ++j) M[i][j] = max(M[i][j - 1], (int)a[j]);
    }

    auto get_idx = [&](int val) {
        return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
    };

    ll ans = 0;
    for (int c1 = 0; c1 < n; ++c1) {
        if (a[c1] >= h) continue;
        ll d1 = G[c1][get_idx(a[c1])];
        ans = max(ans, d1); 
        for (int c2 = c1 + 1; c2 < n; ++c2) {
            if (a[c2] >= h) continue;
            ll d2 = G[c2][get_idx(a[c2])];
            int mid_max = M[c1][c2];
            ll intersect = (mid_max < h) ? G[c1][get_idx(mid_max)] : 0;
            ans = max(ans, d1 + d2 - intersect);
        }
    }
    cout << ans << "\n";
}