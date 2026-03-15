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
#define inp(n) for (int i = 1; i <= n; i++)
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll inf = 1e9;

void solve();
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Input/Output go bRRRRRRRRR!!!!

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }

    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), c(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    ll start = 0;
    ll mx = -inf;
    for (ll i = 0; i < n; ++i)
    {
        mx = max(mx, a[i] * b[i] - c[i]);
        start += a[i] * (b[i] - 1);
    }
    x -= start;
    if (x <= 0)
    {
        cout << 0;
        return;
    }
    if (mx <= 0)
    {
        cout << -1;
        return;
    }
    cout << (x + mx - 1) / mx;
}
