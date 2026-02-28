#include <bits/stdc++.h>
using namespace std;
/*---------------------Boring-stuff----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
const int MAX_N = 1000005; 
const ll MOD = 1e9 + 7;
bool solve();
void sieve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    //wow change in main templete ahh question :(
    sieve();
    int t=1; 
    cin >> t;
    while (t--) {
        if (solve()) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

int spf[MAX_N];

void sieve() {
    for (int i = 2; i < MAX_N; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j < MAX_N; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

int get_distinct_prime(int x) {
    if (x <= 1 || x >= MAX_N) return 0; 
    int p = spf[x];
    if (p == 0) return 0; 
    while (x % p == 0) x /= p;
    return (x == 1) ? p : -1; 
}

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool sorted = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i-1]) sorted = false;
    }

    if (sorted) return false; 

    int last_p = 0;
    bool seen_non_one = false;
    for (int x : a) {
        if (x == 1) {
            if (seen_non_one) return true;
        } else {
            int p = get_distinct_prime(x);
            if (p == -1 || p < last_p) return true; 
            last_p = p;
            seen_non_one = true;
        }
    }
    return false; 
}