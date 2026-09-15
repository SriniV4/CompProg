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
struct Point {
    ll x, y;
    Point() : x(0), y(0) {}
    Point(ll x, ll y) : x(x), y(y) {}

    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator*(ll k) const { return Point(x * k, y * k); }

    bool operator==(const Point& o) const { return x == o.x && y == o.y; }
    bool operator!=(const Point& o) const { return !(*this == o); }
    bool operator<(const Point& o) const { return x != o.x ? x < o.x : y < o.y; }

    ll cross(const Point& o) const { return x * o.y - y * o.x; }
    ll dot(const Point& o) const { return x * o.x + y * o.y; }
    ll norm2() const { return x * x + y * y; }
};
// cross of (b-a) and (c-a): >0 if c is left of ab, <0 right, =0 collinear
ll cross(const Point& a, const Point& b, const Point& c) {
    return (b - a).cross(c - a);
}
istream& operator>>(istream& in, Point& p) { return in >> p.x >> p.y; }
ostream& operator<<(ostream& out, const Point& p) { return out << p.x << " " << p.y; }

const int MAXN = 2e5;
Point arr[MAXN];
int n;
void solve(){
	cin >> n;
	if(!n)exit(0);
	set<Point> st;
	int m= n;
	int ind = 0;
	for(int i =0 ;i<m;i++){
		Point p;
		cin >> p;
		if(st.count(p)){
			n--;
			continue;
		}
		st.insert(p);
		arr[ind++] = p;
	}
	if(n==1){
		cout << 1 << "\n";
		cout << arr[0] << "\n";
		return;
	}
	sort(arr , arr+n);
	stack<Point> s;
	s.push(arr[0]), s.push(arr[1]);
	for(int i =2 ;i<n;i++){
		while(sz(s)>=2){
			Point p = s.top(); s.pop();
			Point pp = s.top();
			if(cross(pp , p , arr[i]) > 0){
				s.push(p);
				break;
			}
		}
		s.push(arr[i]);
	}
	s.pop();
	stack<Point> t;
	t.push(arr[n-1]), t.push(arr[n-2]);
	for(int i =n-3 ;~i;--i){
		while(sz(t)>=2){
			Point p = t.top(); t.pop();
			Point pp = t.top();
			if(cross(pp , p , arr[i]) > 0){
				t.push(p);
				break;
			}
		}
		t.push(arr[i]);
	}
	t.pop();
	cout << sz(s) + sz(t) << "\n";
	vector<Point> ss , tt;
	while(sz(s))ss.pb(s.top()), s.pop();
	while(sz(t))tt.pb(t.top()) , t.pop();
	reverse(all(ss)) , reverse(all(tt));
	for(auto& d : ss)cout << d<< "\n";
	for(auto& d : tt)cout << d << "\n";
}

int main(){
    setIO();
    while(1){
        solve();
    }
}
