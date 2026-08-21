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
const int MAXN = 2e5;
int n ,m;
vi G[MAXN];
int vis[MAXN];
void solve(){
    cin >> n >> m;
    for(int i =0 ;i<n;i++)clr(G[i]) , vis[i] = 0;
    for(int i = 0;i<m;i++){
        int u , v;
        cin >> u >>v , --u , --v;
        G[u].pb(v) , G[v].pb(u);
    }
    int k = 3;
    while(k * k < n)k++;
    if(k*k  != n){
        cout << "NO\n";
        return;
    }
    set<int> thr;
    vi tt;
    for(int i = 0;i<n;i++)
        if(sz(G[i]) == 4)thr.insert(i) , tt.pb(i);
        else if(sz(G[i]) == 2){;}
        else {
            cout << "NO\n";
            return;
        }
    if(sz(thr) != k){
        cout << "NO\n";
        return;
    }
    int prv = -1;
    int curr = *(thr.begin()); 
    while(!vis[curr]){
        vis[curr] = 1;
        int next = -1;
        int cnt = 0;
        for(auto& neigh : G[curr])if(thr.count(neigh)){
            cnt++;
            if(neigh != prv)next = neigh;
        }
        if(cnt != 2){
            cout << "NO\n";
            return;
        }
        assert(next != -1);
        prv = curr;
        curr = next;
    }
    if(curr != *(thr.begin())){
       cout << "NO\n";
       return;
    }
    for(auto& d : tt){
        if(!vis[d]){
            cout << "NO\n";
            return;
        }
    }
    int nNow = 3;
    for(auto& d : tt){
        nNow+=2;
        int cnt = 0;
        vis[d] = 0;
        prv = -1;
        curr = d;
        while(!vis[curr]){
            vis[curr] = nNow;
            if(curr == d)vis[curr]++;
            cnt++;
            int next = -1;
            for(auto& neigh : G[curr])if(!vis[neigh] || vis[neigh] == nNow+1){
                if(neigh != prv)next = neigh;
            }
            if(next == -1){
               cout << "NO\n";
               return;
            }
            prv= curr;
            curr = next;
        }
        if(cnt != k || curr != d){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 0;i<n;i++)assert(vis[i]);
    cout << "YES\n";
}

int main(){
    setIO();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
