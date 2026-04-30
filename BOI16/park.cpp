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
struct dsu{
	vi par;
	dsu(int n){
		reset(n);
	}
	void reset(int n){
		par.assign(n , -1);
	}
	int get(int a){
		return par[a] < 0 ? a : par[a] = get(par[a]);
	}
	bool connected(int a,  int b){
		return get(a) == get(b);
	}
	void connect(int a, int b){
		int pa = get(a) , pb = get(b);
		if(pa == pb)return;
		if(pa < pb) // a is bigger than b
			swap(pa , pb);
		// a is smaller than b
		par[pb] += par[pa];
		par[pa] = pb;
	}
};
struct circle{
	int a , b , r;
};
struct query{
	int r , e , i;
};
struct edge{
	int u , v , w;
};
int n , q;
const int MAXN = 2000;
const int MAXQ = 1e5;
circle arr[MAXN];
int ans[4][4];
int fin[MAXQ][4];
query queries[MAXQ];
int h , w;
void solve(){
	auto getDist = [&](pi i, pi j){
		// change to bin if precision issues
		return (int)sqrt(((i.f - j.f) * (i.f - j.f) + (i.s - j.s) * (i.s-j.s)));
	};
	cin >> n >> q;
	cin >> w >> h;
	for(int i = 0;i<n;i++)cin >> arr[i].a >> arr[i].b >> arr[i].r;
	for(int i =0;i<q;i++)cin >> queries[i].r >> queries[i].e , queries[i].i =i;
	sort(queries, queries + q , [&](auto& a , auto& b){return a.r < b.r;});
	dsu g(n+4); // n, n+1 , n+2 , n+3 will be T R B L 
	vector<edge> all;
	for(int i =0 ;i<n;i++){
		for(int j = i+1;j<n;j++){
			all.pb({i , j, (getDist({arr[i].a , arr[i].b} , {arr[j].a , arr[j].b})- arr[i].r - arr[j].r)/2});
		}
		all.pb(edge{i , n, (h-arr[i].b - arr[i].r)/2});
		all.pb(edge{i , n+1 , (w-arr[i].a - arr[i].r)/2});
		all.pb(edge{i , n+2 , (arr[i].b - arr[i].r)/2});
		all.pb(edge{i , n+3 , (arr[i].a - arr[i].r)/2});
	}
	sort(all(all) , [&](auto& a , auto& b){return a.w < b.w;});
	for(int j = 0;j<4;j++)ans[j][j] = 1;
	int p = 0;
	for(int i = 0;i<q;i++){
		while(p < sz(all) && all[p].w < queries[i].r)g.connect(all[p].u , all[p].v) , p++;
		int ind = queries[i].i;
		for(int j = 0;j<4;j++)for(int k =j+1 ;k<4;k++)ans[j][k] = 0;
		// 12 
		if(!( g.connected(n , n+2) || g.connected(n+1 , n+2) || g.connected(n+2 , n+3)))ans[0][1] = 1;
		// 13
		if(!( g.connected(n , n+2) || g.connected(n+1 , n) || g.connected(n+2 , n+3) || g.connected(n+1 , n+3)))ans[0][2] = 1;
		//14
		if(!( g.connected(n , n+3) || g.connected(n+3 , n+2) || g.connected(n+1 , n+3)))ans[0][3] = 1;
		//23
		if(!( g.connected(n , n+1) || g.connected(n+1 , n+2) || g.connected(n+1 , n+3)))ans[1][2] = 1;
		// 24
		if(!( g.connected(n , n+2) || g.connected(n+3 , n) || g.connected(n+2 , n+1) || g.connected(n+1 , n+3)))ans[1][3] = 1;
		//34
		if(!( g.connected(n , n+2) || g.connected(n+3 , n) || g.connected(n+1 , n)))ans[2][3] = 1;
		int k = queries[i].e-1;
		for(int j = 0;j<4;j++)if(ans[j][k] || ans[k][j])fin[ind][j] = 1;
	}
	for(int i = 0;i<q;i++){
		for(int j = 0;j<4;j++)if(fin[i][j])cout << j+1;
		cout << "\n";
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







