#include <iostream>
#include <vector>

using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    const int MOD = 1e9 + 7;

    // Initial boundary checks
    if (a[0] < n - 1 || a[0] > n) return 0;

    long long ans = 1;
    long long V = 1; // Number of available safe values to reuse

    if (a[0] == n) {
        ans = n; 
    } else {
        ans = 1; // b[0] must be n
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1] || a[i] < (n - 1 - i)) return 0;

        if (a[i] == a[i - 1]) {
            // Must fill one of the (n-i) holes
            ans = (ans * (n - i)) % MOD;
        } else {
            // a[i] < a[i-1]. Must pick a safe value (already present or old mex)
            ans = (ans * (V + 1)) % MOD;
        }
        V++;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}