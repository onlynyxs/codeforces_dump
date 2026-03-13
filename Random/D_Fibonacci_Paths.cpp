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
#define inp(n) for (int i = 0; i < n; i++)
const int MAX_N = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 2e18;

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
struct Edge
{
    int u, v;
    ll s;
    Edge() {}
    Edge(int u, int v, ll s) : u(u), v(v), s(s) {}
    bool operator<(const Edge &other) const
    {
        return s < other.s;
    }
};

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> g(n);
    vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        edges.push_back(Edge(u, v, a[u] + a[v]));
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    vector<map<ll, int>> sumdp(n);

    int ans = 0;

    for (auto e : edges)
    {
        int u = e.u;
        int v = e.v;
        ll s = e.s;
        int curdp = sumdp[v][s];
        add(curdp, 1);
        add(sumdp[u][a[v]], curdp);
        add(ans, curdp);
    }

    cout << ans;
}