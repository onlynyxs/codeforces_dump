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
    int n;
    cin >> n;
    int r[3], c[3];
    for (int i = 0; i < 3; i++) cin >> r[i] >> c[i];
    int x, y;
    cin >> x >> y;

    int r0, c0;
    if (r[0] == r[1] || r[0] == r[2]) 
    r0 = r[0];
    else 
    r0 = r[1];
    
    if (c[0] == c[1] || c[0] == c[2]) 
    c0 = c[0];
    else 
    c0 = c[1];

    bool is_corner = ((r0 == 1 || r0 == n) && (c0 == 1 || c0 == n));

    if (is_corner) {
        if (x == r0 || y == c0) 
        cout << "YES" << endl;
        else 
        cout << "NO" << endl;
    } else {
        if (abs(x - r0) % 2 == 0 || abs(y - c0) % 2 == 0) 
        cout << "YES" << endl;
        else 
        cout << "NO" << endl;
    }
}