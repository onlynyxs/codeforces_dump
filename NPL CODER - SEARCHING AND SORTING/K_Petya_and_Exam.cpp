#include <bits/stdc++.h>
using namespace std;
/*---------------------Boring-stuff----------------------*/
string yes = "YES", no = "NO";
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size()) 
#define all(a) (a).begin(), (a).end()
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
void solve();
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    //Input/Output go bRRRRRRRRR!!!!
    int t=1; 
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
 
    return 0;
}
/*---------------------☆*: .｡. o(≧▽≦)o .｡.:*☆----------------------*/

struct Problem {
    ll mandatory_time;
    int difficulty;
};

void solve () {
    ll num_problems, total_time, easy_cost, hard_cost;
    cin >> num_problems >> total_time >> easy_cost >> hard_cost;

    vector<Problem> tasks(num_problems);
    ll total_easy = 0, total_hard = 0;

    for (int i = 0; i < num_problems; ++i) {
        cin >> tasks[i].difficulty;
        if (tasks[i].difficulty == 0) total_easy++;
        else total_hard++;
    }

    for (int i = 0; i < num_problems; ++i) {
        cin >> tasks[i].mandatory_time;
    }

    sort(tasks.begin(), tasks.end(), [](const Problem &a, const Problem &b) {
        return a.mandatory_time < b.mandatory_time;
    });

    tasks.push_back({total_time + 1, 0});

    ll max_points = 0;
    ll mandatory_easy = 0;
    ll mandatory_hard = 0;

    for (int i = 0; i <= num_problems; ++i) {
        ll deadline = tasks[i].mandatory_time - 1;
        ll time_spent = mandatory_easy * easy_cost + mandatory_hard * hard_cost;

        if (time_spent <= deadline) {
            ll remaining_time = deadline - time_spent;
            ll extra_easy = min(total_easy - mandatory_easy, remaining_time / easy_cost);
            remaining_time -= extra_easy * easy_cost;
            ll extra_hard = min(total_hard - mandatory_hard, remaining_time / hard_cost);
            
            max_points = max(max_points, mandatory_easy + mandatory_hard + extra_easy + extra_hard);
        }

        if (i < num_problems) {
            if (tasks[i].difficulty == 0) mandatory_easy++;
            else mandatory_hard++;
        }

        while (i < num_problems && tasks[i].mandatory_time == tasks[i + 1].mandatory_time) {
            i++;
            if (tasks[i].difficulty == 0) mandatory_easy++;
            else mandatory_hard++;
        }
    }

    cout << max_points;
}