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
const int MAXN = 1e6 + 1;
vector<pair<int , pi>> G[MAXN];
int a[MAXN];
int ans[MAXN];
int done[MAXN];
int cnt = 0;
void dfs(int curr){
    while(sz(G[curr])){
        auto item = G[curr].back();
        G[curr].pop_back();
        if(done[item.s.f])continue;
        done[item.s.f] = 1;
        if(item.s.s)ans[item.s.f] = 1 , cnt++;
        dfs(item.f);
    }
}
void solve(){
    cin >> n;
    map<int , int> cn;
    for(int i=0 ;i<n;i++){
        done[i+1] = ans[i] = 0;
        cin >> a[i], --a[i];
        cn[a[i]]++;
        clr(G[i]);
    }
    for(int i =0 ;i<n;i++){
        int b;
        cin >> b , --b;
        cn[b]++;
        G[a[i]].pb({b, {i+1 , 0}});
        G[b].pb({a[i], {i+1 , 1}});
    }
    for(auto& [c , d] :cn)if(d%2){
        cout << -1 << "\n";
        return;
    }
    cnt = 0; 
    for(int i =0;i<n;i++){
        dfs(i);
    }
    cout << cnt << "\n";
    for(int i = 1;i<=n;i++)if(ans[i])cout << i << " ";
    cout << "\n";
}

int main(){
    setIO();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
