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
struct BIT{
    vll tree;
    BIT(int n){tree.assign(n+1 , 0);}
    void add(int ind , ll num) {
        if(ind < sz(tree))
            tree[ind] += num , add(ind + (ind & -ind) , num);
    }
    ll pref(int ind) {
        return tree[ind] + (ind?pref(ind - (ind & -ind)):0);
    }
    ll query(int l , int r) {
        return pref(r) - (l?pref(l-1):0);
    }
};
int n , d;
ll sm(BIT& b, int ind){
    ind += n;
    ll ans = b.query(ind-d+1 , ind + d+1);
    return ans;
}
const int MAXN = 2e5;
pi arr[MAXN];
void solve(){
    cin >> n >> d;
    BIT full(3*n), cnt(3*n) , sum(3*n);
    for(int i = 0;i<n;i++){
        cin >> arr[i].f, full.add(i+1 , arr[i].f) , full.add(i+1+n , arr[i].f) , full.add(i+1+2*n , arr[i].f);
        arr[i].s = i; 
    }
    sort(arr , arr+n, greater<pi>());
    ll ans = 0;
    for(int i = 0;i<n;i++){
        int ind = arr[i].s , val = arr[i].f;
        // moving from 0 to 1 gains us all the zeros ( not counted )
        ll num = 1+sm(cnt , ind), s = val +  sm(sum , ind) , tot = sm(full , ind);
        ll gain = (d * 2 + 1 - num) * val - (tot - s);
        ll loss = s - num * val;
        if(gain  - loss >= 0){
            ans += gain - loss;
            ind++;
            sum.add(ind, val) , sum.add(ind + n , val) , sum.add(ind + 2*n , val);
            cnt.add(ind , 1) , cnt.add(ind + n , 1), cnt.add(ind + 2*n , 1);
        }
    }
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
