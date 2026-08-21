#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//typedef __int128 lll;
#define PI 3.14159265358979323846
#define sbits(x) __builtin_popcountll(x)
#define tbits(total_size, num) ((total_size) - __builtin_clz(num))
#define pb push_back
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin(), ds.end()
#define pi pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define sz(i) (int)i.size()
using namespace std;
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
uint64_t time() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
int rand(int a , int b){
    return a + rand()%(b-a+1);
}
void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
bool ckmin(auto& a , auto b){if(a<=b)return 0; else {a=b;return 1;}}
bool ckmax(auto& a , auto b){if(a>=b)return 0; else {a=b;return 1;}}
/*
 _______________________________________
( If you don't fail at least 90% of the )
( time, you're not aiming high enough.  )
(                                       )
( - Alan Kay                            )
 ---------------------------------------
        o   ^__^
         o  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/
string q(string& query){
    cout << "? " << query << "\n" << flush;
    string ans;
    cin >> ans;
    return ans;
}
int n;
void solve(){
    cin >> n;
    vector<vi> splits;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)arr[i] = i;
    splits.pb(arr);
    while(sz(splits) != n){
        string query(n , '0');
        int curr = 0;
        for(auto& d : splits){
            for(int j = 0;j<sz(d)/2;j++){
                query[curr + j]++;
            }
            curr += sz(d);
        }
        string ans = q(query);
        vector<vi> newSplits;
        for(auto& d : splits){
            vi o , z;
            for(int i = 0;i<sz(d);i++){
                if(ans[d[i]] == '0')
                    z.pb(d[i]);
                else o.pb(d[i]);
            }
            if(sz(o))
                newSplits.pb(o) ;
            if(sz(z))newSplits.pb(z);
        }
        splits = newSplits;
    }
    vi ans(n);
    for(int i = 0;i<n;i++){
        ans[splits[i][0]] =i ;
    }
    cout << "! ";
    for(auto&  d : ans)cout << d+1 << " ";
    cout << "\n";
    cout << flush;

}

int main(){
    setIO();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
