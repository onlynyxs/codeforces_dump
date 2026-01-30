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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    
    vector<int> s = a;
    sort(s.begin(), s.end());
    
    bool already_sorted = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != s[i]) {
            already_sorted = false;
            break;
        }
    }
    
    if (already_sorted) {
        cout << -1 << "\n";
        return;
    }
    
    int s1 = s[0];
    int sn = s[n - 1];
    int k = 2e9; 
    
    for (int i = 0; i < n; ++i) {
        if (a[i] != s[i]) {
            int flex = max(abs(a[i] - s1), abs(a[i] - sn));
            k = min(k, flex);
        }
    }
    
    cout << k << "\n";
}