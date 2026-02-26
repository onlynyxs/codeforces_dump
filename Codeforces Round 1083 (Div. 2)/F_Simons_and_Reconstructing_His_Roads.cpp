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

struct DSU {
    vector<int> parent;
    vector<ll> sum;
    vector<bool> grounded;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sum.assign(n, 0);
        grounded.assign(n, false);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            sum[root_j] += sum[root_i];
            grounded[root_j] = grounded[root_j] || grounded[root_i];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> w(n - 1, vector<int>(m)), v(n, vector<int>(m - 1));
    for (auto &row : w) for (auto &x : row) cin >> x;
    for (auto &row : v) for (auto &x : row) cin >> x;

    vector<string> p(n - 1), q(n);
    for (auto &s : p) cin >> s;
    for (auto &s : q) cin >> s;

    DSU dsu((n - 1) * (m - 1));
    auto get_idx = [&](int r, int c) { return r * (m - 1) + c; };

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            dsu.sum[get_idx(i, j)] = (ll)w[i][j] - w[i][j + 1] + v[i][j] - v[i + 1][j];
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (p[i][j] == '0') {
                if (j == 0) dsu.grounded[dsu.find(get_idx(i, 0))] = true;
                else if (j == m - 1) dsu.grounded[dsu.find(get_idx(i, m - 2))] = true;
                else dsu.unite(get_idx(i, j - 1), get_idx(i, j));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (q[i][j] == '0') {
                if (i == 0) dsu.grounded[dsu.find(get_idx(0, j))] = true;
                else if (i == n - 1) dsu.grounded[dsu.find(get_idx(n - 2, j))] = true;
                else dsu.unite(get_idx(i - 1, j), get_idx(i, j));
            }
        }
    }

    ll total = 0;
    for (int i = 0; i < (n - 1) * (m - 1); ++i) {
        if (dsu.parent[i] == i && !dsu.grounded[i]) {
            if (dsu.sum[i] > 0) total += dsu.sum[i];
        }
    }
    cout << total ;
}