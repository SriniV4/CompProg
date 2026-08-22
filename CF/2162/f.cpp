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
int n , m;
const int MAXN = 3000;
pi arr[MAXN];
int p[MAXN+1];
int l[MAXN], r[MAXN];
void solve(){
    cin >> n >> m;
    for(int i = 0;i<n;i++)p[i] = l[i] = r[i] = 0;
    for(int i = 0;i<m;i++){
        cin >> arr[i].f >> arr[i].s , --arr[i].f , --arr[i].s , p[arr[i].f]++ , p[arr[i].s+1]-- , l[arr[i].f]++ , r[arr[i].s]++;
    }
    
    for(int i = 0;i<n;i++){
        if(i)p[i] += p[i-1];
        if(p[i]==m){
            int pp = 1;
            for(int j = 0;j<n;j++){
                cout << (j == i?0:pp++) << " ";
            }
            cout << "\n";
            return;
        }
    }
    for(int i= 0;i<n-1;i++){
        if(r[i] == 0 || l[i+1] == 0){
            int pp = 2;
            for(int j = 0;j<i;j++)cout << pp++ << " ";
            if(l[i+1])
                cout << "0 1 ";
            else cout << "1 0 ";
            for(int j = i+2;j<n;j++)cout << pp++ << " ";
            cout << "\n";
            return;
        }
    }
    for(int i = 1;i<n;i++)cout << i << " ";
    cout << 0 << "\n";
}

int main(){
    setIO();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
