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
const int INF = 1e9;

void solve();
int main() {
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    
    
    int t=1; 
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n, k, v;
    cin >> n >> k >> v;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> order;
    vector<int> parent(n + 1, 0);
    vector<int> visit_stack = {v};
    parent[v] = -1;

    while(!visit_stack.empty()){
        int curr = visit_stack.back();
        visit_stack.pop_back();
        order.push_back(curr);
        for(int neighbor : adj[curr]){
            if(neighbor != parent[curr]){
                parent[neighbor] = curr;
                visit_stack.push_back(neighbor);
            }
        }
    }

    vector<int> l_dist(n + 1, INF);
    vector<int> dp(n + 1, INF);

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        bool is_leaf = true;
        vector<int> effective_child_vals;
        int min_l = INF;

        for (int neighbor : adj[u]) {
            if (neighbor != parent[u]) {
                is_leaf = false;
                min_l = min(min_l, l_dist[neighbor]);

                int best_from_child = min(l_dist[neighbor], dp[neighbor]);
                if (best_from_child < k) {
                    effective_child_vals.push_back(best_from_child);
                }
            }
        }

        if (is_leaf) {
            l_dist[u] = 0;
            dp[u] = 0;
        } else {
            l_dist[u] = 1 + min_l;

            if (effective_child_vals.size() >= 2) {
                sort(effective_child_vals.begin(), effective_child_vals.end());
                dp[u] = 1 + effective_child_vals[1]; 
            } else {
                dp[u] = INF;
            }
        }
    }

    int winning_children = 0;
    for (int neighbor : adj[v]) {
        if (min(l_dist[neighbor], dp[neighbor]) < k) {
            winning_children++;
        }
    }

    cout << (winning_children >= 2 ? yes : no);
}