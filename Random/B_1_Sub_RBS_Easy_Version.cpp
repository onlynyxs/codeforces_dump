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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> nx(n + 2, n + 1);
    vector<int> suf(n + 2, 0);

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            nx[i] = i;
            suf[i] = 1 + suf[i + 1];
        } else {
            nx[i] = nx[i + 1];
            suf[i] = suf[i + 1];
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')' && nx[i] < n) {
            int ig = nx[i] - i; 
            if (nx[i] + 1 <= n && suf[nx[i] + 1] >= ig) {
                ans = max(ans, n - 2 * ig);
            }
        }
    }
    
    cout << ans;
}