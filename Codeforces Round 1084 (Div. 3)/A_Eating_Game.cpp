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
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    int total_dishes = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_dishes += a[i];
    }

    set<int> winners;

    for (int start_player = 0; start_player < n; start_player++) {
        vector<int> temp_a = a;
        int remaining = total_dishes;
        int curr = start_player;

        while (remaining > 0) {
            if (temp_a[curr] > 0) {
                temp_a[curr]--;
                remaining--;
                
                if (remaining == 0) {
                    winners.insert(curr);
                    break;
                }
            }
            curr = (curr + 1) % n;
        }
    }

    cout << winners.size();
}