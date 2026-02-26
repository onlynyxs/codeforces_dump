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
bool global_seen[1000005];

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> bur(n);
    vector<int> all_mentions; 
    
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vector<int> a(l);
        for (int j = 0; j < l; ++j) cin >> a[j];
        
        vector<int> s;
        set<int> local_seen;
        for (int j = l - 1; j >= 0; --j) {
            if (local_seen.find(a[j]) == local_seen.end()) {
                s.push_back(a[j]);
                local_seen.insert(a[j]);
                all_mentions.push_back(a[j]);
            }
        }
        bur[i] = s;
    }

    vector<bool> used(n, false);
    vector<int> q;
    vector<int> gt;

    for (int k = 0; k < n; ++k) {
        int best_idx = -1;
        vector<int> best_t;
        
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            
            vector<int> current_t;
            for (int x : bur[i]) {
                if (!global_seen[x]) {
                    current_t.push_back(x);
                }
            }
            
            if (best_idx == -1 || current_t < best_t) {
                best_idx = i;
                best_t = current_t;
            }
        }
        
        for (int x : best_t) {
            q.push_back(x);
            if (!global_seen[x]) {
                global_seen[x] = true;
                gt.push_back(x);
            }
        }
        used[best_idx] = true;
    }

    for (int i = 0; i < (int)q.size(); ++i) {
        cout << q[i] << (i == (int)q.size() - 1 ? "" : " ");
    }

    for (int x : gt) global_seen[x] = false;
}