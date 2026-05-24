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
int n , k , arr[MAXN];
void solve(){
    cin >> n >> k;
    for(int i = 0;i<n;i++)cin >> arr[i];
    set<pi> st;
    map<int , int> cnt;
    for(int i = 0;i<k;i++){
        int nC = ++cnt[arr[i]];
        if(nC!=1)st.erase({-nC+1 , arr[i]});
        st.insert({-nC , arr[i]});
    }
    cout << (*(st.begin())).s << ' ';
    for(int i =k;i<n;i++){
        int nC = ++cnt[arr[i]];
        if(nC!=1)st.erase({-nC+1 , arr[i]});
        st.insert({-nC , arr[i]});
        nC = --cnt[arr[i-k]];
        st.erase({-nC-1 , arr[i-k]});
        if(nC)st.insert({-nC , arr[i-k]});
        cout << (*(st.begin())).s << ' ';
    }
    cout << "\n";
}

int main(){
    setIO();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
