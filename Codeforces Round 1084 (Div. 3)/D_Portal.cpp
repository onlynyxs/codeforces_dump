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
int gms(const vector<int>& s) {
    int n = s.size();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int a = s[(i + k) % n], b = s[(j + k) % n];
        if (a == b) k++;
        else {
            if (a > b) i += k + 1;
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return min(i, j);
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int d = y - x;
    if (d == 0) {
        for (int i = 0; i < n; i++) cout << p[i] << (i == n - 1 ? "" : " ");
        return;
    }

    vector<int> m, s;
    for (int i = 0; i < n; i++) {
        if (i >= x && i < y) m.push_back(p[i]);
        else s.push_back(p[i]);
    }

    int start_idx = gms(m);
    vector<int> m_best;
    for (int i = 0; i < d; i++) m_best.push_back(m[(start_idx + i) % d]);

    int fd = -1;
    for (int j = 1; j < d; j++) {
        if (m_best[j] != m_best[0]) {
            fd = j;
            break;
        }
    }

    int best_i = s.size();
    for (int i = 0; i < s.size(); i++) {
        bool m_better = false;
        if (m_best[0] < s[i]) m_better = true;
        else if (m_best[0] == s[i]) {
            if (fd != -1 && m_best[fd] < m_best[0]) m_better = true;
        }
        if (m_better) {
            best_i = i;
            break;
        }
    }

    for (int i = 0; i < best_i; i++) cout << s[i] << " ";
    for (int i = 0; i < d; i++) cout << m_best[i] << (i == d - 1 && best_i == s.size() ? "" : " ");
    for (int i = best_i; i < s.size(); i++) cout << s[i] << (i == s.size() - 1 ? "" : " ");
}