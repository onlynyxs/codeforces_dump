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
    string s;
    cin >> s;

    int total_min = 0;
    int total_max = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int start = i;
            int end = i;
            int j = i;
            while (j < n) {
                if (s[j] == '1') {
                    end = j; 
                } else if (j + 1 < n && s[j+1] == '0') {
                    break;
                }
                j++;
            }
            
            int L = end - start + 1;
            total_max += L;
            total_min += (L / 2) + 1;
            
            i = end; 
        }
    }

    cout << total_min << " " << total_max;
}