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
const int MAXN = 5e5 + 1;
vi primes;
int tab[MAXN];
void sieve(){
	for(int i = 2;i<MAXN;i++){
		if(!tab[i])primes.pb(i) , tab[i] = i;
		for(auto& p : primes){
			if(p * i >= MAXN)break;
			tab[p * i] = p;
			if(i % p == 0)break;
		}
	}
}
int n;
void solve(){
	sieve();
	cin >> n;
	int l = 0, r = sz(primes)-1;
	while(l<r){
		int m = l + (r-l+1)/2;
		if(primes[m] <= n)l = m;
		else r = m-1;
	}
	for(int i = 0;i<=l;i++)cout << 1 << " ";
	for(ll i = 2;i<=n;i++){
		// number of numbers that are i * p for p < = i and 	
		l = 0, r = sz(primes);
		while(l<r){
			// largest m such that m * i <= n and m <= i
			int m = l + (r-l+1)/2;
			if(primes[m-1] <= tab[i] && primes[m-1] * i <= n)l = m;
			else r = m-1;
		}
		for(int j = 0;j<l;j++)cout << i << " ";
	}
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
