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
    vector<ll> d(2 * n);
    map<ll, int> freq;
    
    for (int i = 0; i < 2 * n; i++) {
        cin >> d[i];
        freq[d[i]]++;
    }

    
    vector<ll> dd;
    for (auto const& [val, count] : freq) {
        if (val % 2 != 0 || count != 2) {
            cout << no;
            return;
        }
        dd.push_back(val);
    }

    if (dd.size() != n) {
        cout << no;
        return;
    }

    sort(dd.rbegin(), dd.rend());

    ll cs = 0;
    vector<ll> x(n);

    for (int i = 0; i < n; i++) {
        ll cnt = n - i; 
        ll numerator = dd[i] - 2 * cs;

        if (numerator <= 0 || numerator % (2 * cnt) != 0) {
            cout << no;
            return;
        }

        ll xi = numerator / (2 * cnt);
        
        if (i > 0 && xi >= x[i-1]) {
            cout << no;
            return;
        }

        x[i] = xi;
        cs += xi;
    }

    cout << yes;
}