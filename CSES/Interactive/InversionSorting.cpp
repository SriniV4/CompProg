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
int q(int l , int r){
    cout << l << " " << r << "\n" << flush;
    int ans;
    cin >> ans;
    if(ans)return ans;
    else {
        exit(0);
    }
}
int n;
void solve(){
    cin >> n;
    int num = q(1, n);
    for(int i = 2;i<=n;i++){
        // reverse [1 , i]
        /*
         * change is (i-1)C2 + 
         *  1 2 3  -> 0
         * 2 1 3 -> 1 
         */
        int next = q(1 ,i);
        q(1 , i);
        int diff = next - num - (i-1) * (i-2)/2;
        for(int j = 1;j<i;j++){
            //    .... j -> +(j-1) - (n-j) = 2j -n -1
            if(2 *j - i-1 == diff){
                // this guy is suppsed to be in jth index
                // [1...j-1] j [j+1...i]
                q(j , i-1);
                num = q(j , i);
            }
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
