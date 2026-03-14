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

int row[1000100];
int col[1000100];
int n,m;
void rearr(){
    for(int i=0;i<=max(n,m);i++){
        row[i]=col[i]=0;
    }
}

void solve() {
    cin >> n >> m;
    rearr();
    int end=-n*m;
    int cnum=0;
    char temp;
    for(int i = 0;i < n*m;i++) {
		cin >> temp;
		temp -= '0';
		if(temp == 1) {
			end = i;
			if(col[i%m] == 0) {
				col[i%m] = 1;
				cnum++;
			}
		}
		if(i - end < m) {
			row[i%m]++;
		}
		if(i!=0) cout << ' ';
		cout << row[i%m]+ cnum;
		
	}
}