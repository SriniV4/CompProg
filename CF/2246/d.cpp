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
int n;
const int MAXN = 1e5;
int arr[MAXN];
const int LOG = 20;
ll cost(int z){
    ll tot = z;
    for(int i =0 ;i<n;i++){
        ll cost = INT_MAX;
        for(int tt = z;tt<=LOG;tt++){
            ll cc = 0;
            int goal = (1<<tt);
            int temp = arr[i] + (goal - arr[i]%goal)%goal; 
            cc += temp - arr[i];
            temp >>= z;
            while(temp)cc++, temp = (temp%2?temp-1:temp/2);
            ckmin(cost, cc);
        }
        tot += cost;
    }
    return tot;
}
void solve(){
    cin >> n;
    for(int i =0 ;i<n;i++)cin >> arr[i];
    ll ans = INT64_MAX;
    for(int i = 0;i<=LOG;i++)ckmin(ans , cost(i));
    cout << ans << "\n";
}

int main(){
    setIO();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
