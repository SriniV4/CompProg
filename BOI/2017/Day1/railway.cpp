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
const int MAXN = 1e5;
const int LOG = 30;
int bin[MAXN][LOG];
int dep[MAXN];
vpi G[MAXN];
int n;
void con(){
	for(int i = 1;i<LOG;i++){
		for(int j = 0;j<n;j++)
		if(bin[j][i-1] == -1)bin[j][i] = -1;
		else bin[j][i] = bin[bin[j][i-1]][i-1];
	}
}
int t[MAXN];
int p = 0;
int tim[MAXN];
void build(int curr = 0, int par = -1){
	bin[curr][0] = par;	
	tim[curr] = p++;
	for(auto& [neigh , ind] : G[curr])if(neigh != par)
		dep[neigh] = dep[curr] + 1, build(neigh , curr) , t[neigh] = ind;
}
int cnt[MAXN];
int lca(int a, int b){
	if(dep[a] < dep[b])swap(a , b);
	int da = dep[a] , db = dep[b];
	int diff = da - db;
	for(int i = 0;i<LOG;i++)if((1<<i) & diff)a = bin[a][i];
	// cerr << dep[a] << " " << dep[b] << " " << a << " " << b << "\n";
	if(a == b)return a;
	// jump until same
	for(int i = LOG-1;i>=0;--i)if(bin[a][i] != bin[b][i]){
		// cerr << bin[a][i] << " " << bin[b][i] << "\n";
		a = bin[a][i] , b = bin[b][i];
	}
	return bin[a][0];
}
void upd(int a, int b){
	if(dep[a] > dep[b])swap(a , b); // b is deweper
	int lc = lca(a ,b );
	// cerr << a << "  "<< b << " " << lc << "\n";
	cnt[b]++;
	cnt[lc]--;
	if(a != lc)
		cnt[a]++ , cnt[lc]--;
}
void sm(int curr = 0, int par = -1){
	for(auto& [neigh , ind] : G[curr])if(neigh != par)
		sm(neigh , curr) , cnt[curr] += cnt[neigh];
}
int m , k;
void solve(){
	cin >> n >> m >> k;
	for(int i = 1;i<n;i++){
		int u , v;
		cin >> u >>v , --u , --v;
		G[u].pb({v , i}) , G[v].pb({u , i});
	}
	build();
	con();
	for(int i = 0;i<m;i++){
		int s;
		cin >> s;
		vi arr(s);
		for(auto& a : arr)
			cin >> a , --a;
		sort(all(arr) , [&](int a, int b){return tim[a] < tim[b];});
		for(int j = 0;j<sz(arr);j++){
			upd(arr[j] , arr[(j+1)%sz(arr)]);	
		}
	}
	sm();
	vi ans;
	for(int i =1 ;i<n;i++){
		if(cnt[i]/2 >= k){
			ans.pb(t[i]);
		}
	}
	sort(all(ans));
	cout << sz(ans) << "\n";
	for(auto& d : ans)cout << d << " ";
	cout << "\n";
}

int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
