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
const int MOD = 1e9+7;
struct mint{
    ll x;
    mint(ll num=0){x=(num%MOD+MOD)%MOD;}
    mint& operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}
    mint& operator-=(const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD;return *this;}
    mint& operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}
    mint operator+(const mint a) const {mint res(*this);return res+=a;}
    mint operator-(const mint a) const {mint res(*this);return res-=a;}
    mint operator*(const mint a) const {mint res(*this);return res*=a;}
    mint pow(ll b) const{
      mint ans(1) , curr(*this);
      while(b){
          if(b%2)
              ans *= curr;
          curr *= curr;
          b>>=1;
      }
      return ans;
    }
    mint inv() const{
      return pow(MOD-2);
    }
    mint& operator/=(const mint a) {return (*this) *= a.inv();}
    mint operator/(const mint a) const {mint res(*this);return res/=a;}
};
ostream& operator<<(ostream& os, const mint& a) {os << a.x; return os;}
int n;
void solve(){
    map<int , int> cnt;
    set<int> arr;
    cin >> n;
    for(int i = 0 , a;i<n;i++){
        cin >> a;
        cnt[a]++;
        arr.insert(a);
    }
    ll temp = 0;
    mint ans = 0;
    for(auto& [a , b] : cnt){
        temp += b-1;
    }
    ans = mint(2).pow(temp); 
    if(cnt[-1])
        for(auto& d : arr)if(arr.count(d+1)){
            ans += mint(2).pow(temp);
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
