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
const int MAXN = 1e5;
vi adj[MAXN];
int col[MAXN];
bool bip = true;
int cnt = 0;
void dfs(int curr){
	cnt++;
	for(auto& neigh : adj[curr]){
		if(col[neigh] == -1){
			col[neigh] = !col[curr];
			dfs(neigh);
		}
		if(col[neigh] == col[curr])bip = false;
	}
}
void solve(){
	cin >> n >> m;
	memset(col , 0xff, sizeof(col));
	for(int i = 0;i<m;i++){
		int u , v;
		cin >> u >> v , --u ,--v, adj[u].pb(v) , adj[v].pb(u);
	}
	ll numComp = 0;
	ll numBip = 0;
	ll numOne = 0;
	for(int i = 0;i<n;i++){
		if(col[i] == -1){
			bip = true, cnt = 0;
			dfs(i);
			if(cnt==1)numOne++;
			else numComp++, numBip += bip;
		}
	}
	ll ans = numComp * numComp + numBip * numBip + ((n+0ll) * n - (n-numOne) * (n-numOne));
	cout << ans << "\n";
}

int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
