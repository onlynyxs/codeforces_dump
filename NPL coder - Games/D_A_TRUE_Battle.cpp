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
    string s;
    cin >> s;

    bool alice_wins = false;

    if (s[0] == '1' || s[n - 1] == '1') {
        alice_wins = true;
    } 
    else {
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '1' && s[i + 1] == '1') {
                alice_wins = true;
                break;
            }
        }
    }

    if (alice_wins) {
        cout << yes << "\n";
    } else {
        cout << no << "\n";
    }
}