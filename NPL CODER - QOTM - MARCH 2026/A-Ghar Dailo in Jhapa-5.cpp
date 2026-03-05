// #include <bits/stdc++.h>
// using namespace std;
// /*---------------------Boring-stuff----------------------*/
// string yes = "YES", no = "NO";
// #define ar array
// #define ll long long
// #define ld long double
// #define sza(x) ((int)x.size())
// #define all(a) (a).begin(), (a).end()
// const int MAX_N = 1e5 + 5;
// const ll MOD = 1e9 + 7;
// void solve();
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     // Input/Output go bRRRRRRRRR!!!!
//     int t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//         cout << endl;
//     }

//     return 0;
// }
// /*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

// void solve()
// {
//     int total_candidates, total_houses;
//     cin >> total_candidates >> total_houses;

//     if (total_houses < 2)
//     {
//         for (int i = 0; i < total_candidates; i++)
//         {
//             cout << 0 << (i == total_candidates - 1 ? "" : " ");
//         }
//         return;
//     }

//     vector<bool> is_house_neutral(total_houses + 1, true);
//     is_house_neutral[0] = false;
//     is_house_neutral[1] = false;

//     vector<int> neutral_divisors_per_house(total_houses + 1, 0);

//     for (int divisor = 2; divisor <= total_houses; divisor++)
//     {
//         for (int multiple = divisor; multiple <= total_houses; multiple += divisor)
//         {
//             neutral_divisors_per_house[multiple]++;
//         }
//     }

//     vector<long long> convinced_per_candidate(total_candidates, 0);
//     int houses_left_to_convince = total_houses - 1;

//     for (int day = 0; day < 60 && houses_left_to_convince > 0; day++)
//     {
//         int best_target_house = -1;
//         int max_impact = -1;

//         for (int h = 2; h <= total_houses; h++)
//         {
//             if (is_house_neutral[h])
//             {
//                 if (neutral_divisors_per_house[h] > max_impact)
//                 {
//                     max_impact = neutral_divisors_per_house[h];
//                     best_target_house = h;
//                 }
//             }
//         }

//         if (best_target_house == -1)
//             break;

//         int current_candidate_index = day % total_candidates;
//         int convinced_today = 0;

//         for (int d = 1; d * d <= best_target_house; d++)
//         {
//             if (best_target_house % d == 0)
//             {

//                 int potential_divisors[2] = {d, best_target_house / d};

//                 for (int div : potential_divisors)
//                 {
//                     if (div > 1 && is_house_neutral[div])
//                     {

//                         is_house_neutral[div] = false;
//                         convinced_today++;
//                         houses_left_to_convince--;

//                         for (int m = div; m <= total_houses; m += div)
//                         {
//                             neutral_divisors_per_house[m]--;
//                         }
//                     }

//                     if (d * d == best_target_house)
//                         break;
//                 }
//             }
//         }
//         convinced_per_candidate[current_candidate_index] += convinced_today;
//     }

//     for (int i = 0; i < total_candidates; i++)
//     {
//         if (i > 0)
//             cout << " ";
//         cout << convinced_per_candidate[i];
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int n, k, m, b, a[20], v[130005], s[130005], t, i, j;
int main()
{
    cin >> n >> k;
    for (; t < 60; t++)
    {
        for (m = b = 0, i = 2; i <= k; i++)
            s[i] = 0;
        for (i = 2; i <= k; i++)
            if (!v[i])
                for (j = i; j <= k; j += i)
                    s[j]++;
        for (i = 2; i <= k; i++)
            if (!v[i] && s[i] > m)
                m = s[b = i];
        if (!m)
            break;
        a[t % n] += m;
        for (i = 2; i <= b; i++)
            if (b % i == 0)
                v[i] = 1;
    }
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}