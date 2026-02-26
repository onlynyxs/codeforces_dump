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
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll count = 0;

    for(ll i = 0; i <= n - k;) {

        bool can = true;

        for(ll j = 0; j < k; j++) {
            if(a[i + j] == 1) {
                can = false;
                break;
            }
        }

        if(can) {
            count++;
            i += k + 1; 
        }
        else {
            i++;
        }
    }

    cout << count << '\n';
}