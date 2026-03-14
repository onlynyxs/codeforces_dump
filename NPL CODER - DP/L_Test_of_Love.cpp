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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
   
    string river = "L" + s + "L";
    
    int current = 0;
    int swim_dist = 0;
    
    while (current <= n) {
        if (river[current] == 'L') {
            bool jumped = false;
            
            for (int i = min(current + m, n + 1); i > current; i--) {
                if (river[i] == 'L') {
                    current = i;
                    jumped = true;
                    break;
                }
            }
            
            if (jumped) continue;
            
            for (int i = min(current + m, n + 1); i > current; i--) {
                if (river[i] == 'W') {
                    current = i;
                    jumped = true;
                    break;
                }
            }
            
            if (!jumped) {
                cout << no;
                return;
            }
        } 
        else if (river[current] == 'W') {
            current++;
            swim_dist++;
            
            if (current <= n && river[current] == 'C') {
                cout << no;
                return;
            }
        } 
        else { 
            cout << no;
            return;
        }
        
        if (swim_dist > k) {
            cout << no;
            return;
        }
    }
    
    cout << yes;
}