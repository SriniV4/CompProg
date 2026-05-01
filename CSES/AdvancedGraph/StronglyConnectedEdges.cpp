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
vi G[MAXN];
vpi ans;
bitset<MAXN> vis;
int low[MAXN];
int depth[MAXN];
int cnt = 0;
void dfs(int curr = 0 , int par =-1){	
	cnt++;
	vis[curr] = 1;
	low[curr] = depth[curr];
	for(auto& neigh : G[curr]){
		if(vis[neigh]) { // back edge 
			if(neigh != par) ckmin(low[curr] , depth[neigh]);
			if(depth[neigh] > depth[curr])ans.pb({neigh+1 , curr+1});
		}  else {
			depth[neigh] = depth[curr] + 1;
			dfs(neigh , curr);
			ckmin(low[curr] , low[neigh]);
			ans.pb({curr+1 , neigh+1});
		}
	}
	// cout << curr << depth[curr] << " " << low[curr] << "\n";
	if(curr && low[curr] == depth[curr]){
		cout << "IMPOSSIBLE\n";
		exit(0);
	}
}
void solve(){
	cin >> n >> m;
	for(int i= 0 , a , b ;i<m;i++)cin >> a >> b , --a , --b , G[a].pb(b) , G[b].pb(a);
	dfs();
	if(cnt != n || sz(ans) != m){
		cout << "IMPOSSIBLE\n";
	} else 
	for(auto& [a , b] : ans)cout << a << " " << b << "\n";
}

int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
