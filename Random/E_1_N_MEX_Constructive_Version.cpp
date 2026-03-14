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
        // cout << "\n";
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (a[0] > n) { cout << no << endl; return; }
    for (int i = 0; i < n; ++i) {
        if (a[i] < n - 1 - i) { cout << no << endl; return; }
        if (i > 0 && a[i] > a[i - 1]) { cout << no << endl; return; }
    }

    vector<bool> is_mex(n + 1, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= n) is_mex[a[i]] = true;
    }

    vector<long long> U;
    for (int i = 0; i < a[0]; ++i) {
        if (!is_mex[i]) U.push_back(i);
    }

    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            if (a[0] == n) {
                b[i] = U.back();
                U.pop_back();
            } else {
                b[i] = n + 1;
            }
        } else {
            if (a[i] == a[i - 1]) {
                b[i] = U.back();
                U.pop_back();
            } else {
                b[i] = a[i - 1];
            }
        }
    }

    cout << yes << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}
