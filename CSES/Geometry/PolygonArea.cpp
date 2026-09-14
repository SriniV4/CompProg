#include <bits/stdc++.h>
#include <memory>
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
int n;
const int MAXN = 1000;
Point arr[MAXN];
void solve(){
    cin >> n;
    for(int i = 0;i<n;i++)cin >> arr[i];
    ll ans =0 ;
    for(int i = 0;i<n;i++)ans += cross({0 , 0} , arr[i] , arr[(i+1)%n]);
    cout << abs(ans) << "\n";
}

int main(){
    setIO();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
