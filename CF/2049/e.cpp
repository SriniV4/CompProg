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
int query(int l , int r){
	l++ , r++;
	cout << "? " << l <<  " " << r << "\n" << flush;
	int ans;
	cin >> ans;
	return ans;
}
void ans(int k){
	cout << "! " << k << "\n" << flush;
}
int bin(int l, int r, int x){ // find leftmost occrunece of x
	int left = l;
	while(l<r){
		int m = l + (r-l)/2;
		if(query(left , m) == x)r = m;
		else l =m+1;
	}
	return r;
}
int n;
void solve(){
	cin >> n;
	vi bits(4);
	for(int i = 0;i<3;i++){
		bits[i] = query(0+n/4 * i, (i+1ll) * (n/4) - 1);
	}
	int s = bits[0] + bits[1] + bits[2];
	bits[3] = 1^(s%2);
	s += bits[3];
	if(s==3){
		// k <= n/4
		int l , r;
		if(bits[0] == 1)l = 0 , r = n/4-1;
		else l = n/4 , r = n/2-1;
		// binary search this range
		// find left most occurence of 1
		int left = bin(l , r , 1);
		ans(left - l + 1);
		return;
	}
	// k > n/4
	// check <= n/2
	int l = -1;
	for(int i = 0;i<3;i++)if(bits[i] + bits[i+1] == 0)l =i;
	int left = l * (n/4), right = (l+2ll) * (n/4) - 1;
	int bit = query(left , right);
	if(bit == 1){
		// k <= n/2
		int leftl = bin(left , right , 1);
		ans(leftl - left+1);
		return;
	}
	if(bits[0] + bits[1] == 1){
		left = n/2 , right = n-1;
		while(left < right){
			int m = left + (right-left)/2;
			if(query(0 , m) == 0) right = m;
			else left = m +1;
		}
		ans(left+1);
	} else {
		left = 0, right = n/2-1;
		while(left < right){
			int m = left + (right - left+1)/2;
			if(query(m , n-1) == 0)left =m;
			else right = m-1;
		}
		ans(n-left);
	}
}

int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
