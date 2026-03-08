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

    vector<int>a(n), b(n);

        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        vector<pair<int,int>> ops;

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
                ops.push_back({3, i+1});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                if (a[j] > a[j+1]) {
                    swap(a[j], a[j+1]);
                    ops.push_back({1, j+1});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                if (b[j] > b[j+1]) {
                    swap(b[j], b[j+1]);
                    ops.push_back({2, j+1});
                }
            }
        }

        cout << ops.size()<< endl;
        for (auto [t,i] : ops)
            cout << t << " " << i << endl;
}