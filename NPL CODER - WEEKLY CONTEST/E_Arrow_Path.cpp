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
        cout << "\n";
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

void solve() {
    int n;
    cin >> n;
    string g[2];
    cin >> g[0] >> g[1];

    vector<vector<bool>> vis(2, vector<bool>(n, false));
    queue<pair<int, int>> a;

    a.push({0, 0});
    vis[0][0] = true;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    bool possible = false;
    while (!a.empty()) {
        auto [r, c] = a.front();
        a.pop();

        if (r == 1 && c == n - 1) {
            possible = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < 2 && nc >= 0 && nc < n) {
                if (g[nr][nc] == '>') nc++;
                else nc--;

                if (nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    a.push({nr, nc});
                }
            }
        }
    }

    cout << (possible ? "YES" : "NO");
}