#include <bits/stdc++.h>
using namespace std;
/*---------------------Boring-stuff----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
const int MAX = 200005; 
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

ll tree_sum[4 * MAX];
int tree_cnt[4 * MAX];

void update(int node, int start, int end, int idx, int val, int add) {
    if (start == end) {
        tree_cnt[node] += add;
        tree_sum[node] += (ll)val * add;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val, add);
    else update(2 * node + 1, mid + 1, end, idx, val, add);
    tree_cnt[node] = tree_cnt[2 * node] + tree_cnt[2 * node + 1];
    tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
}

ll query(int node, int start, int end, int k) {
    if (k <= 0) return 0;
    if (tree_cnt[node] <= k) return tree_sum[node];
    if (start == end) return (ll)(tree_sum[node] / tree_cnt[node]) * k;
    
    int mid = (start + end) / 2;
    if (tree_cnt[2 * node + 1] >= k) {
        return query(2 * node + 1, mid + 1, end, k);
    } else {
        return tree_sum[2 * node + 1] + query(2 * node, start, mid, k - tree_cnt[2 * node + 1]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> energies;
    vector<vector<int>> by_y(n + 2);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        energies.push_back(a[i].first);
    }
    
    sort(energies.begin(), energies.end());
    energies.erase(unique(energies.begin(), energies.end()), energies.end());
    int num_unique = energies.size();

    for (int i = 0; i < n; i++) {
        int rank = lower_bound(energies.begin(), energies.end(), a[i].first) - energies.begin() + 1;
        by_y[a[i].second].push_back(rank);
    }

    fill(tree_sum, tree_sum + 4 * num_unique + 1, 0);
    fill(tree_cnt, tree_cnt + 4 * num_unique + 1, 0);

    ll M = 0;
    vector<ll> g(n + 2, -1e18); 
    
    for (int k = n + 1; k >= 1; k--) {
        if (k - 1 <= n) {
            for (int rank : by_y[k - 1]) {
                update(1, 1, num_unique, rank, energies[rank - 1], 1);
            }
        }
        
        int current_total = tree_cnt[1];
        if (current_total >= k) {
            M = max(M, query(1, 1, num_unique, k));
        }
        if (current_total >= k - 1) {
            g[k] = query(1, 1, num_unique, k - 1);
        } else {
            g[k] = -1e18; 
        }
    }

    vector<ll> prefG(n + 2);
    ll cur_max = -1e18;
    for (int k = 1; k <= n + 1; k++) {
        cur_max = max(cur_max, g[k]);
        prefG[k] = cur_max;
    }

    for (int j = 0; j < m; j++) {
        int xs, ys;
        cin >> xs >> ys;
        ll ans = M;
        int limit = min(ys + 1, n + 1);
        if (limit >= 1) {
            ans = max(ans, (ll)xs + prefG[limit]);
        }
        cout << ans << (j == m - 1 ? "" : " ");
    }
}