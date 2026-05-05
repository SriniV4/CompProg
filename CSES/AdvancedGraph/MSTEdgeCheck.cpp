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
	int size(int a){
		return -par[get(a)];
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
int n , m;
const int MAXN = 2e5;
int ans[MAXN];
struct edge{
	int u , v ,w , i;
};
edge arr[MAXN];
void solve(){
	cin >>n >> m;
	int w;
	for(int i = 0 , u , v;i<m;i++)cin >> u >> v >> w, --u , --v ,arr[i] = edge{u , v , w , i};
	sort(arr , arr+m , [&](auto& a , auto& b){return a.w < b.w;});
	int p = 0;
	dsu graph(n);
	while(p < m){
		int w = arr[p].w;
		int l = p;
		while(l < m && arr[l].w == w){
			if(!graph.connected(arr[l].u , arr[l].v))
				ans[arr[l].i]= 1;
			l++;
		}
		l = p;
		while(l < m && arr[l].w == w){
			graph.connect(arr[l].u , arr[l].v);
			l++;
		}
		p = l;
	}
	for(int i = 0;i<m;i++)cout << (ans[i]?"YES":"NO") << "\n";
}

int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
