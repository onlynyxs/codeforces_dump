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
    string s;
    cin >> s;

    int sum = 0;
    for (char c : s) sum += (c - 'a' + 1);

    int n = s.size();

    if (n % 2 == 0) {
        cout << "Alice " << sum << '\n';
    } else {
        int L = s[0] - 'a' + 1;
        int R = s[n - 1] - 'a' + 1;
        int bob = min(L, R);
        int alice = sum - bob;

        if (alice > bob) {
            cout << "Alice " << (alice - bob) << '\n';
        } else {
            cout << "Bob " << (bob - alice) << '\n';
        }
    }
}
