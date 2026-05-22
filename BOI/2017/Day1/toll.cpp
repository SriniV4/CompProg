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
const int INF = 1e9;
const int MAXN = 5e4;
const int LOG = 21;
int nxt[MAXN][LOG][5];
int n , k , m;
void bin(){
	for(int i = 1;i<LOG;i++){ // jump size
		for(int j = 0;j<n;j++){ // node
			for(int l = 0;l<k;l++){ // final output 
				ll mn = INF;
				for(int o = 0;o<k;o++){ // intermediate output
					int nextNode = (j/k+(1<<(i-1)))*k + o;
					if(nextNode >= n)break;
					ckmin(mn , nxt[j][i-1][o] + nxt[nextNode][i-1][l]);
				}
				nxt[j][i][l]= mn;
			}
		}
	}
}
int q;
void solve(){
	cin >> k >> n >> m >> q;
	for(int i = 0;i<n;i++)for(int l = 0;l<LOG;l++)for(int j = 0;j<k;j++)
		nxt[i][l][j] = INF;
	for(int i = 0,u , v;i<m;i++){
		cin >> u >> v;
		int t;
		cin >> t;
		nxt[u][0][v%k] = t;	
	}
	bin();
	for(int i = 0;i<q;i++){
		int a , b;
		cin >> a >> b;
		if(b/k <= a/k){
			cout << -1 << "\n";
			continue;
		}
		int diff = b/k - a/k;
		vi dist(k , INF);
		dist[a%k] = 0;
		int curr = a/k;
		for(int j = 0;j<LOG;j++)if((1<<j) & diff){
			// jump	
			vi next;
			for(int o = 0;o<k;o++){
				ll ans = INF;
				for(int mid = 0;mid<k;mid++){
					int node = curr * k + mid;
					ckmin(ans , dist[mid] + nxt[node][j][o]);
				}
				next.pb(ans);
			}
			curr += (1<<j);
			swap(next , dist);
		}
		cout << (dist[b%k] == INF?-1:dist[b%k]) << "\n";
	}
}

int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
