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
int vis[MAXN];
int col[MAXN];
array<int , 3> queries[MAXN];
void solve(){
	cin >> n >> m;
	for(int i = 0 ,u , v;i<m;i++)cin >> u >> v , --u , --v , G[u].pb(v) , G[v].pb(u);
	memset(vis , 0xff , sizeof(vis));
	int q;
	cin >> q;
	for(int i = 0;i<q;i++){
		int a , b , c;
		cin >> a >> b >> c;
		--a , queries[i] = {a , b , c};
	}
	for(int i = q-1;i>=0;--i){
		int start = queries[i][0];
		int d = queries[i][1];
		int c = queries[i][2];
		if(vis[start] >= d)continue;
		if(col[start] == 0)col[start] = c;
		queue<int> q;
		if(d)
			q.push(start);
		vis[start] = d;
		while(sz(q)){
			auto next = q.front();
			q.pop();
			for(auto& neigh : G[next])if(vis[neigh] < vis[next] - 1){
				if(vis[neigh] == -1)col[neigh] = c;
				vis[neigh] = vis[next] -1;
				if(vis[neigh])q.push(neigh);
			}
		}
	}
	for(int i =0 ;i<n;i++)cout << col[i] << "\n";
}

int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
