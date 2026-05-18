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
const int MAXN = 2e5 + 1;
mint f[MAXN];
mint inv[MAXN];
void build(){
	f[0] = 1;
	for(int i = 1;i<MAXN;i++)f[i] = f[i-1] * i;
	inv[MAXN-1] = f[MAXN-1].inv();
	for(int i = MAXN-2;i>=0;--i)inv[i] = inv[i+1] * (i+1);
}
int n;
vi col[MAXN];
void solve(){
	cin >> n;
	int a, b; // a is same, b is diff
	cin >> a >> b;
	for(int i =0;i<n;i++){
		int x , y;
		cin >> x >> y , --x;
		col[x].pb(y);
	}
	int mn = INT_MAX, ind = -1, smn = b;
	for(int i =0 ;i<n;i++)if(sz(col[i])){
		sort(all(col[i]));
		if(col[i][0] <= mn)smn = mn, mn = col[i][0] , ind = i;
		else if(col[i][0] <= smn)smn = col[i][0];
	}
	if(mn + smn > b){
		cout << 1 << '\n';
		return;
	}
	mint ans = 1;
	int tot = 0;
	for(int i = 0;i<n;i++)if(sz(col[i]) && (i== ind || (b >= mn + col[i][0]))){
		int cnt = 0;		
		for(int j = 0;j<sz(col[i]);j++){
			// check if connected to smallest
			if(j==0 && i == ind){
				cnt++; // this is the smallest
				continue;
			}
			int cmp = (i == ind ? smn : mn);
			if(col[i][j] + cmp <= b){
				cnt++;
				continue;
			}
			// cant connect to someone else, must connect to front
			if(col[i][j] + col[i][0] <= a){
				cnt++;
				continue;
			}
			break;
		}
		ans *= inv[cnt];
		tot += cnt;
	}
	ans *= f[tot];
	cout << ans << "\n";
}

int main(){
	setIO();
	int t = 1;
	build();
	//cin >> t;
	while(t--){
		solve();
	}
}
