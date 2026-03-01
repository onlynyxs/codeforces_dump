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
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    bool all_less_equal = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > d) {
            all_less_equal = false;
        }
    }

    if (all_less_equal) {
        cout << yes;
        return;
    }

    sort(a.begin(), a.end());

    if (a[0] + a[1] <= d) {
        cout << yes;
    } else {
        cout << no ;
    }
}