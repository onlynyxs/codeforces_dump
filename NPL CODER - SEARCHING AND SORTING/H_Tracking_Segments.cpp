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
        cout << endl;
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/
void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> segs(m);
    for(int i = 0; i < m; i++) {
        cin >> segs[i].first >> segs[i].second;
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    int left = 1, right = q;
    int answer = -1;

    while(left <= right) {
        int mid = (left + right) / 2;

        vector<int> a(n + 1, 0);

        for(int i = 0; i < mid; i++) {
            a[queries[i]] = 1;
        }

        vector<int> pref(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i];
        }

        bool found = false;

        for(auto [l, r] : segs) {
            int ones = pref[r] - pref[l - 1];
            int len = r - l + 1;

            if(2 * ones > len) {
                found = true;
                break;
            }
        }

        if(found) {
            answer = mid;
            right = mid - 1;  
        } else {
            left = mid + 1;
        }
    }

    cout << answer;
}