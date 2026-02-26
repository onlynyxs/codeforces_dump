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
        cout <<endl;
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<int> pmax(n + 1);
        vector<ll> psum(n + 1);
        for(int j = 0; j < n; j++)
        {
            pmax[j + 1] = max(pmax[j], a[j]);
            psum[j + 1] = psum[j] + a[j];
        }
        for(int k = 1; k <= n; k++)
            cout << pmax[n - k + 1] + psum[n] - psum[n - k + 1] << " ";
    
}