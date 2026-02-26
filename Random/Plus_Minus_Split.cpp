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
bool isEqual(vector<int> &arr){
    int tar=arr[0];
    int n=arr.size();
    for(int i=1;i<n;i++) if(arr[i] != tar) return false;
    return true;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(isEqual(arr)){
        cout<<yes;
        return;
    }
    for(int i=0;i<n;i++){
        vector<int> part(n);
        for(int j=0;j<n;j++){
            if(j<i) part[j] = arr[j] + arr[i];
            else part[j] = arr[j] - arr[i];
        }
        if(isEqual(part)){
             cout<<yes;
            return;
        }
    }
    cout<<no;
}