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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    inp(n) cin >> a[i];
    vector<ll> b(n + 5);
    for (ll i = 0; i < n + 5; i++)
        b[i] = 0;
    ll mex = 0;
    for (ll i = 1; i <= n; i++)
        b[a[i]]++;
    while (b[mex])
        mex++;
    cout << min(mex, m - 1);
}