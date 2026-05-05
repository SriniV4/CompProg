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
int n , k;
const int MAXN = 2e5+1;
vi g1[MAXN];
vi g2[MAXN];
int arr1[MAXN] , arr2[MAXN];
pi o[MAXN*3]; // {outi-1, ini+1}
pi t[MAXN]; // {ini , outi}
// check if o is a rotation of t
bitset<MAXN> v1 , v2;
void d1(int start = 0 , int col = 0){
	v1[start] = 1;	
	if(arr1[start])o[(col+1)%k].f++;
	else o[((col-1)%k+k)%k].s++;
	for(auto& neigh : g1[start])if(!v1[neigh])
		d1(neigh , col+1);
}
void d2(int start = 0, int col = 0){
	v2[start] = 1;
	if(arr2[start])t[col%k].s++;
	else t[col%k].f++;
	for(auto& neigh : g2[start])if(!v2[neigh])
		d2(neigh , col+1);
}
int pref[MAXN*3];
bool prefF(){
	pref[0] = 0;
	int p = 0;
	for(int i = 1;i<=3*k;i++){
		pref[i] = 0;
		while (p > 0 && o[i] != o[p]) p = pref[p-1];
		if (o[i] == o[p]) p++;
		pref[i] = p;
		if (p == k) return true;
	}
	return false;
}
void solve(){
	cin >> n >> k;
	int s1 = 0, s2= 0;
	for(int i =0 ;i<n;i++)cin >> arr1[i] , v1[i] = v2[i] = 0 , o[i] = t[i] = {0 , 0} , clr(g1[i]) , clr(g2[i]) , s1 += arr1[i];
	int m; cin >> m;
	for(int i = 0 , u , v;i<m;i++)cin >> u >> v , --u , --v , g1[u].pb(v);
	for(int i =0 ;i<n;i++)cin >> arr2[i] , s2 += arr2[i];
	cin >> m;
	for(int i = 0 , u , v;i<m;i++)cin >> u >> v , --u , --v , g2[u].pb(v);
	if(min(s1 , s2)==0 && max(s1, s2)==n){
		cout << "YES\n";
		return;
	}
	d1() , d2();
	// check spin
	o[k] = {-1 , -1};
	for(int i = k+1;i<=3*k;i++)o[i] = t[(i-1)%k];
	// run pref func
	cout << (prefF()?"YES":"NO") << "\n";
}

int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
