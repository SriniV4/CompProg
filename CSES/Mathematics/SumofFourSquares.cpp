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
const int MAXN = 1e7+1;
pi arr[MAXN];
bitset<MAXN> exists;
void build(){
    for(int i = 0;i*i<MAXN;i++){
        for(int j =i;i*i + j*j<MAXN;j++){
            int num = i * i + j * j;
            if(!exists[num]){
                arr[num] = {i , j};
                exists[num] = 1;
            }
        }
    }
}
void solve(){
    auto print = [&](int a , int b, int c , int d){cout << a << " "<< b << " " << c << " " << d << "\n";};
    cin >> n;
    for(int i = 0;i*i<=n;i++){
        for(int j =i;i*i + j*j<=n;j++)if(exists[n-i*i-j*j]){
            pi it = arr[n-i*i - j*j];
            print(i , j, it.f , it.s);
            return;
        }
    }
}
int main(){
    setIO();
    int t = 1;
    cin >> t;
    build();
    while(t--){
        solve();
    }
}
