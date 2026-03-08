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
        cout << "\n";
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/
void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    set<int> pos;
    pos.insert(x);

    for (int i = 0; i < m; i++) {
        int r;
        char c;
        cin >> r >> c;

        set<int> next_pos;
        for (int p : pos) {
            if (c == '0' || c == '?') {
                int nxt = (p + r - 1) % n + 1;
                next_pos.insert(nxt);
            }
            if (c == '1' || c == '?') {
                int nxt = (p - r - 1 % n + n) % n + 1;
                next_pos.insert(nxt);
            }
        }
        pos = next_pos; 
    }

    cout << pos.size() << "\n";
    for (auto it = pos.begin(); it != pos.end(); ++it) {
        cout << *it << (next(it) == pos.end() ? "" : " ");
    }
}