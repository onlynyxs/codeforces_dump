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
    int n,m,k;
    cin>>n>>m>>k;
        if(k-1<n-k)k=n+1-k;
        int a=0,b=0;
        while(1){
            if(b<n-k&&a+(b+1)+max(a,b+1)-1<=m)++b;
            if(a<k-1&&(a+1)+b+max(a+1,b)-1<=m)++a;
            else break;
        }
        cout<<a+b+1<<endl;
}
