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

ll get_closest(ll target, ll mask) {
    if ((target & mask) == 0) return target;

    int highest_collision = -1;
    for (int i = 30; i >= 0; i--) {
        if ((target >> i & 1) && (mask >> i & 1)) {
            highest_collision = i;
            break;
        }
    }

    ll lwr = 0;
    for (int i = 30; i > highest_collision; i--) {
        if (target >> i & 1) lwr |= (1LL << i);
    }
    for (int i = highest_collision - 1; i >= 0; i--) {
        if (!(mask >> i & 1)) lwr |= (1LL << i);
    }

    int ff = -1;
    for (int i = highest_collision; i <= 31; i++) {
        if (!(target >> i & 1) && (!(mask >> i & 1))) {
            ff = i;
            break;
        }
    }
    ll high = 0;
    for (int i = 31; i > ff; i--) {
        if (target >> i & 1) high |= (1LL << i);
    }
    high |= (1LL << ff);

    if (abs(target - lwr) <= abs(target - high)) return lwr;
    return high;
}

void solve() {
    ll x, y;
    cin >> x >> y;

    ll p1 = get_closest(x, y);
    ll q1 = y;
    
    ll q2 = get_closest(y, x);
    ll p2 = x;

    if (abs(x - p1) + abs(y - q1) <= abs(x - p2) + abs(y - q2)) {
        cout << p1 << " " << q1 << "\n";
    } else {
        cout << p2 << " " << q2 << "\n";
    }
}