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
//this is to anonny them AI users hunters ☆*: .｡. o(≧▽≦)o .｡.:*☆
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll total_students = 0;
    int prev_idx = -2; 

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            total_students++;
            int gap = i - prev_idx - 1;
            total_students += (gap / 3);
            prev_idx = i;
        }
    }

    int final_gap = (n + 1) - prev_idx - 1;
    total_students += (final_gap / 3);

    cout << total_students << "\n";
}