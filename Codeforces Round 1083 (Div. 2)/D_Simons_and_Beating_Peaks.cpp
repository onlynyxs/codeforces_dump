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

const int MAXN = 500005;
const int K = 20;
int st[MAXN][K];
int lg[MAXN];
int a[MAXN];

void build(int n) {
    for (int i = 0; i < n; i++) st[i][0] = i;
    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            int left = st[i][j - 1];
            int right = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = (a[left] > a[right]) ? left : right;
        }
    }
}

int query(int L, int R) {
    int j = lg[R - L + 1];
    int left = st[L][j];
    int right = st[R - (1 << j) + 1][j];
    return (a[left] > a[right]) ? left : right;
}

ll get_min_ops(int L, int R) {
    if (R - L + 1 <= 2) return 0; 

    int mid = query(L, R);
    
    ll move_left = (mid - L) + get_min_ops(mid + 1, R);
    ll move_right = (R - mid) + get_min_ops(L, mid - 1);

    return min(move_left, move_right);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    build(n);
    cout << get_min_ops(0, n - 1);
}