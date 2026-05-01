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
const int MAXN = 2500;
vi adj[MAXN];
int dist[MAXN][MAXN][2];
const int INF = 1e9;
int n, m;
void solve(){
	auto bfs = [&](int start) -> void{
		queue<pi> q;
		q.push({start , 0});
		dist[start][start][0] = 0;	
		while(sz(q)){
			auto temp= q.front();
			int next= temp.f , currDist = temp.s;
			q.pop();
			for(auto& neigh : adj[next])if(ckmin(dist[start][neigh][(currDist%2)^1] , currDist + 1))
				q.push({neigh , currDist+1});
		}
	};
	int q;
	cin >> n >> m >> q;
	for(int i = 0, u ,  v;i<m;i++)
		cin >> u >> v , --u ,--v, adj[u].pb(v) , adj[v].pb(u);
	for(int i =0 ;i<n;i++){
		for(int j = 0;j<n;j++)
			dist[i][j][0] = dist[i][j][1] = INF;
		bfs(i);
	}
	for(int i =0 ;i<q;i++){
		int u , v , x;
		cin >> u >> v >> x , --u , --v;
		cout << (dist[u][v][x%2] <= x ? "YES":"NO") << "\n";
	}
}

int main(){
	setIO();
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}	
}







