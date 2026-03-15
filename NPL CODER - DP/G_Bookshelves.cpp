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
const int MAX_N = 55;
const ll MOD = 1e9 + 7;

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

int n, k_target;
ll s[MAX_N];
bool feas[MAX_N][MAX_N];

inline bool dp_check(ll targ, ll mask) {
    memset(feas, false, sizeof(feas));
    feas[0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (((s[i] - s[j]) & mask & targ) == targ) {
                for (int count = 0; count < n; ++count) {
                    if (feas[j][count]) {
                        feas[i][count + 1] = true;
                    }
                }
            }
        }
    }
    
    return feas[n][k_target];
}

void solve() {
    cin >> n >> k_target;    
    vector<ll> a(n);
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    ll ans = 0;
    for (int i = 60; i >= 0; i--) {
        ll current_mask = ~((1LL << i) - 1);
        ll trial_ans = ans | (1LL << i);
        
        if (dp_check(trial_ans, current_mask)) {
            ans = trial_ans;
        }
    }
    
    cout << ans;
}