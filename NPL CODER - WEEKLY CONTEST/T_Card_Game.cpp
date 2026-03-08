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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a.push_back(i + 1);
        else b.push_back(i + 1);
    }

    bool win = false;
    for (int x : a) {
        bool beatable = false;
        for (int y : b) {
            if ((y > x && !(x == 1 && y == n)) || (y == 1 && x == n)) {
                beatable = true;
                break;
            }
        }
        if (!beatable) {
            win = true;
            break;
        }
    }

    cout << (win ? "Alice" : "Bob");
}