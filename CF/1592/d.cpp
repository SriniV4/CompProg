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
const int MAXN = 1e3;
int n;
vi G[MAXN];
pi tour[MAXN * 2];
int p = 0;
void dfs(int curr = 0, int par = -1){
	for(auto& neigh : G[curr])if(neigh != par){
		tour[p++] = {curr , neigh};
		dfs(neigh , curr);
		tour[p++] = {curr , neigh};
	}
}
int query(set<int>& arr){
	cout << "? ";
	cout << sz(arr) << " ";
	for(auto& d : arr)cout << d << " ";
	cout << flush;
	int a;
	cin >> a;
	return a;
}
void solve(){
	cin >> n;
	set<int> q;
	for(int i= 0;i<n;i++)q.insert(i+1);
	for(int i = 0 , u ,v;i<n-1;i++)cin >> u >> v , --u , --v , G[u].pb(v) , G[v].pb(u);
	dfs();
	int mx = query(q);
	int l = 0, r = p-1;
	while(l < r){
		int m = l + (r-l)/2;
		set<int> q;
		for(int i = l;i<=m;i++)q.insert(tour[i].f+1) , q.insert(tour[i].s+1);
		if(query(q) == mx)r = m;
		else l = m + 1;
	}
	cout << "! ";
	cout << tour[l].f+1 << " " << tour[l].s+1 << "\n";
}

int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
