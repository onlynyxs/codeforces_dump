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
    // cin >> t;
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
    vector<string> s(n);
    ll cnt[6][50];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int sum_val = 0;
        for (char c : s[i]) sum_val += (c - '0');
        cnt[s[i].length()][sum_val]++;
    }

    ll total_lucky_pairs = 0;

    for (int i = 0; i < n; ++i) {
        int L = s[i].length();
        vector<int> pref(L + 1, 0);
        for (int j = 0; j < L; ++j) {
            pref[j + 1] = pref[j] + (s[i][j] - '0');
        }
        int total_sum = pref[L];

        for (int len = 1; len <= 5; ++len) {
            if ((L + len) % 2 != 0) continue;

            int mid = (L + len) / 2;

            if (L >= len) {
                int sum_first_half = pref[mid];
                int sum_of_si_in_second_half = total_sum - sum_first_half;
                
                int required_sum_sj = sum_first_half - sum_of_si_in_second_half;

                if (required_sum_sj >= 0 && required_sum_sj < 50) {
                    total_lucky_pairs += cnt[len][required_sum_sj];
                }
            }

            if (L > len) {
                int sum_second_half = total_sum - pref[L - mid];
                int sum_of_si_in_first_half = total_sum - sum_second_half;

                int required_sum_si = sum_second_half - sum_of_si_in_first_half;

                if (required_sum_si >= 0 && required_sum_si < 50) {
                    total_lucky_pairs += cnt[len][required_sum_si];
                }
            }
        }
    }

    cout << total_lucky_pairs;
}