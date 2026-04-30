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
int n , m, k;
const int MAXN = 1e5;
int imp[5];
ll dp[1<<5][MAXN];
vpi adj[MAXN];
const ll INF = 1e18;
void solve(){
	auto djik = [&](int mask){
		priority_queue<pi> pq;
		for(int i = 0;i<n;i++)pq.push({-dp[mask][i] , i});
		while(sz(pq)){
			auto next = pq.top();
			pq.pop();
			ll curr = -next.f , node = next.s;
			if(dp[mask][node] != curr)continue;
			for(auto& [neigh , weight] : adj[node])if(ckmin(dp[mask][neigh] , curr + weight))
				pq.push({-(curr + weight) , neigh});
		}
	};
	cin >> n >> k >> m;
	for(int i = 0;i<k;i++)cin >> imp[i], --imp[i];
	for(int i = 0;i<m;i++){
		int u , v , w;
		cin >> u >> v >> w , --u ,--v , adj[u].pb({v , w}) , adj[v].pb({u , w});
	}
	for(int i = 0;i<k;i++){
		for(int j =0 ;j<n;j++)dp[(1<<i)][j] = INF;
		dp[(1<<i)][imp[i]] = 0;
		djik(1<<i);
	}
	ll ans = INF;
	for(int mask = 1;mask < (1<<k);mask++)if(sbits(mask) >= 2){
		for(int i = 0;i<n;i++){
			dp[mask][i] = INF;
			for(int sub = mask;sub;sub = (sub - 1) & mask)if(sub != mask){
				ckmin(dp[mask][i], dp[sub][i] + dp[mask^sub][i]);
			}
		}
		djik(mask);
	}
	for(int i = 0;i<n;i++)ckmin(ans , dp[(1<<k)-1][i]);
	cout << ans << "\n";
}

int main(){
	setIO();
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}	
}







