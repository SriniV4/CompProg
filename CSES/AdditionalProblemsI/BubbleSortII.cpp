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
struct BIT{
	vll tree;
	BIT(int n){tree.assign(n+1 , 0);}
	void add(int ind , ll num) {
		if(ind < sz(tree))
			tree[ind] += num , add(ind + (ind & -ind) , num);
	}
	ll pref(int ind) {
		return tree[ind] + (ind?pref(ind - (ind & -ind)):0);
	}
	ll query(int l , int r) {
		return pref(r) - (l?pref(l-1):0);
	}
};
int n, k;
const int MAXN = 2e5;
pi arr[MAXN];
int ans[MAXN];
void solve(){
	cin >> n >> k;
	for(int i = 0;i<n;i++)cin >> arr[i].f , arr[i].s = i;
	sort(arr , arr+n);
	BIT b(n);
	for(int i = 0;i<n;i++){
		// how many eles are before
		int ind = arr[i].s;
		int num = b.pref(ind + 1); // how many are less and before
		// it will take ind - num rounds
		if(k <= ind - num){
			ans[ind-k] = arr[i].f;
		} else {
			int rem = k - (ind - num);
			// rem moves left, move forward as much as possible
			int l = ind , r = n-1;
			while(l<r){
				int m = l + (r-l+1)/2;
				// valid?
				// we need total - number of elements marked + 1 <= rem
				int tot = m - ind + 1;
				int marked = b.query(ind+1 , m+1);
				if(tot - marked <= rem)l = m;
				else r = m-1;
			}
			int newInd = num + b.query(ind+1 , l+1);
			ans[newInd] = arr[i].f;
		}
		b.add(arr[i].s + 1 , 1);
	}
	for(int i =0;i<n;i++)cout << ans[i] << " ";
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
