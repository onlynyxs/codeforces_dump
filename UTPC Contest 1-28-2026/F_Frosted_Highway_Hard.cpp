#include <bits/stdc++.h>

using namespace std;

vector<int> valid_indices[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    for (int k = 1; k <= 1000; k++) {
        for (int i = k; i <= n; i += k) {
            if (h[i] % k == 0) {
                valid_indices[k].push_back(i);
            }
        }
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        auto it1 = lower_bound(valid_indices[k].begin(), valid_indices[k].end(), l);
        auto it2 = upper_bound(valid_indices[k].begin(), valid_indices[k].end(), r);
        
        cout << distance(it1, it2) << "\n";
    }

    return 0;
}