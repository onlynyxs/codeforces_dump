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
/*---------------------Look-here-for-logic----------------------*/

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    p[n] = 1; 
    
    int low = 2;
    int high = n;
    bool pick_high = true;

    for (int i = n - 1; i >= 1; --i) {
        if (pick_high) {
            p[i] = high;
            high--;
        } else {
            p[i] = low;
            low++;
        }
        pick_high = !pick_high;
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}