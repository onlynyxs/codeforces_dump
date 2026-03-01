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

bool is_safe(const string& s) {
    for (int i = 0; i < (int)s.size() - 1; ++i) {
        if (abs(s[i] - s[i+1]) == 1) return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    string even = "", odd = "";
    
    for (char c : s) {
        if ((c - 'a') % 2 == 0) even += c;
        else odd += c;
    }
    
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    if (is_safe(even + odd)) {
        cout << even + odd ;
    } else if (is_safe(odd + even)) {
        cout << odd + even ;
    } else {
        cout << "No answer";
    }
}