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
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/
void solve()
{
    int n, k;
        cin >> n >> k;
        int a[k]{}, p = 0;
        if(k&1)
            for(int i = 0; i < k; i++)
                a[i] = n;
        else {
            for(int i = 30; i >= 0; i--) {
                if(n >> i & 1) {
                    for(int j = 0; j < k; j++)
                        if(j != min(p, k-1))
                            a[j] += (1 << i);
                    if(p < k)
                        p++;
                } else
                    for(int j = 0; j < p/2*2; j++)
                        a[j] += (1 << i);
            }
        }
        for(int i = 0; i < k; i++)
            cout << a[i] << (i+1 == k? '\n':' ');
    }