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
const int MAXN = 5001;
int dp[MAXN][MAXN];
int ar[MAXN][10];
int br[MAXN][10];
string a , b;
void solve(){
    cin >> a;
    cin >> b;
    int n = sz(a) , m = sz(b);
    for(int i = 0;i<max(m, n);i++)for(int j = 0;j<10;j++)ar[i][j] = br[i][j] = -1;
    for(int i = n-1;i>=0;--i){
        if(i+1<n)
            for(int j = 0;j<10;j++)ar[i][j] = ar[i+1][((j-(a[i]-48))%10+10)%10];
        ar[i][a[i]-48] = i;
    }
    for(int i = m-1;i>=0;--i){
        if(i+1<m)
            for(int j = 0;j<10;j++)br[i][j] =br[i+1][((j-(b[i]-48))%10+10)%10];
        br[i][b[i]-48] = i;
    }
    dp[n][m] = 0;
    for(int i = n-1;i>=0;--i){
        for(int j =m-1;j>=0;--j){
            
        }
    }
}

int main(){
    setIO();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
