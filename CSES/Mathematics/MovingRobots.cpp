#include <bits/stdc++.h>
#include <sys/wait.h>
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
ld ans[8][8];
ld dp[8][8];
ld prv[8][8];
int neigh[8][8];
int k;
void solve(){
    cin >> k;    
    for(int i =0 ;i<8;i++){
        for(int j= 0;j<8;j++){
            int cnt = 0;
            for(int l = 0;l<4;l++){
                int nX = i + xP[l] , nY = j + yP[l];
                if(nX>=0 && nY>=0 && nX<8 && nY<8)cnt++;
            }
            neigh[i][j] = cnt;
            ans[i][j] = 1;
        }
    }
    for(int i = 0;i<8;i++){
        for(int j= 0;j<8;j++){
            // which cells can the robot here visit
            memset(prv , 0 , sizeof(prv));
            prv[i][j] = 1;  
            // prv[i][j] = probability robot is at cell i , j after k moes
            for(int it = 0;it<k;it++){
                for(int x = 0;x<8;x++){
                    for(int y = 0;y<8;y++){
                        dp[x][y] = 0;
                        // probability it is here
                        for(int o = 0;o<4;o++){
                            int nX = x + xP[o] , nY = y+yP[o];
                            if(nX>=0 && nY>=0 && nX<8 && nY<8){
                                dp[x][y] += prv[nX][nY]/neigh[nX][nY];
                                // dp[x][y] += dp[nX][nY]/neigh[x][y];
                            }
                        }
                    }
                }
                swap(dp , prv);
            }
            for(int x = 0;x<8;x++){
                for(int y = 0;y<8;y++){
                    ans[x][y] *= 1 - prv[x][y];
                }
            }
        }
    }
    ld sum = 0;
    for(int i = 0;i<8;i++){
        for(int j= 0;j<8;j++){
            sum += ans[i][j]; 
        }
    }
    cout << fixed << setprecision(6);
    cout << sum << "\n";
}

int main(){
    setIO();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
