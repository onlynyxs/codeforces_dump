#include <stdio.h>
#include <stdbool.h>

#define MAX_K 130005

int n, k;
bool v[MAX_K];   

int s[MAX_K];    

long long a[105]; 

int main() {
    if (scanf("%d %d", &n, &k) != 2) return 0;

    if (k < 2) {
        for (int i = 0; i < n; i++) {
            printf("0%c", (i == n - 1 ? '\n' : ' '));
        }
        return 0;
    }

    for (int i = 2; i <= k; i++) v[i] = true;

    for (int i = 2; i <= k; i++) {
        for (int j = i; j <= k; j += i) {
            s[j]++;
        }
    }

    int rem = k - 1; 

    for (int t = 0; t < 60 && rem > 0; t++) {
        int best = -1, mx = -1;

        for (int i = 2; i <= k; i++) {
            if (v[i] && s[i] > mx) {
                mx = s[i];
                best = i;
            }
        }

        if (best == -1) break;

        int cur = t % n;
        int cnt = 0;

        for (int d = 1; (long long)d * d <= best; d++) {
            if (best % d == 0) {
                int factors[2] = {d, best / d};
                for (int f = 0; f < 2; f++) {
                    int val = factors[f];
                    if (val > 1 && v[val]) {
                        v[val] = false;
                        cnt++;
                        rem--;

                        for (int m = val; m <= k; m += val) {
                            s[m]--;
                        }
                    }
                    if (d * d == best) break; 

                }
            }
        }
        a[cur] += cnt;
    }

    for (int i = 0; i < n; i++) {
        printf("%lld%c", a[i], (i == n - 1 ? '\n' : ' '));
    }

    return 0;
}