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
    // cin >> t;
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

    vector<int> sushi(n);
    for (int i = 0; i < n; ++i) {
        cin >> sushi[i];
    }

    vector<int> groups;
    int current_count = 1;
    for (int i = 1; i < n; ++i) {
        if (sushi[i] == sushi[i - 1]) {
            current_count++;
        } else {
            groups.push_back(current_count);
            current_count = 1;
        }
    }
    groups.push_back(current_count);

    int max_len = 0;
    for (int i = 0; i < (int)groups.size() - 1; ++i) {
        int valid_half = min(groups[i], groups[i+1]);
        max_len = max(max_len, 2 * valid_half);
    }

    cout << max_len;
}