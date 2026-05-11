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
int n, k;
int query(int team, int num){
	if(num == 0)return INT_MAX;
	if(num == n+1)return INT_MIN;
	cout << (team?"S":"F") << " " << num << "\n" << flush;
	int ans;
	cin >> ans;
	return ans;
}
void ans(int num){
	cout << "! " << num << "\n";
	exit(0);
}
void solve(){
	cin >> n >> k;
	int l = max(0 , k-n) , r = min(n , k);
	while(l<r){
		int mid = l +(r-l)/2;
		// take mid from team 0
		int num1 = query(0 , mid) , num2 = query(1 , k-mid);
		if(num1 < num2){
			if(query(1 , k-mid+1) < num1)ans(num1);
			else r = mid-1;
		} else {
			if(query(0 , mid+1) < num2)ans(num2);
			else l = mid + 1;
		}
	}
	
	ans(min(query(0  , l) , query(1 , k-l)));
}

int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
