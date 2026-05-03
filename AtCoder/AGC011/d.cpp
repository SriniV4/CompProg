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
string line;
string getAns(int jump){
	string ans(n , 0);
	for(int i = 0;i<n;i++)if(i+jump < n){
		ans[i] = line[i+jump];
		if(jump%2)ans[i] = ans[i] == 'A'?'B':'A';
	} else {
		ans[i] = (n-1-i)%2?'B':'A';
	}
	return ans;
}
void solve(){
	cin >> n >> k;
	cin >> line;
	int p = 0;
	int let = 0;
	while(p<n){
		if(k==0){
			cout << getAns(p) << "\n";
			return;
		}
		let = (line[p] - 'A');
		if(p%2)let^=1;
		if(let == 0){
			let = 1;
			k--;
		}
		if(k==0){
			string ans = getAns(p);
			ans[0] = 'B';
			cout << ans << "\n";
			return;
		}
		p++;
		k--;
	}
	string ans = getAns(n);
	if(k%2==1 && n%2)ans[0] = 'B';
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







