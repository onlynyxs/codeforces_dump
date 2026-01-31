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
    // cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    ll final_answer = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        
        ll current_scenario_max = LLONG_MIN;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue; 
            
            for (int k = 0; k < m; ++k) {
                ll product = a[j] * b[k];
                if (product > current_scenario_max) {
                    current_scenario_max = product;
                }
            }
        }

        if (current_scenario_max < final_answer) {
            final_answer = current_scenario_max;
        }
    }

    cout << final_answer << endl;
}