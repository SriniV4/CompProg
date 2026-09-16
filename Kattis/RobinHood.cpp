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
const int MAXN = 1e5;
Point arr[MAXN];
int n;
void solve(){
    cin >> n;
    if(n==0)exit(0);
    int m = n;
    int p = 0;
    set<Point> set;
    for(int i =0 ;i<m;i++){
        Point pp;
        cin >> pp;
        if(set.count(pp)){
            n--;
            continue;
        }
        set.insert(pp);
        arr[p++] = pp;
    }
    if(n==1){
        cout << 0 << "\n";
        return;
    }
    // if(n==2){
    //     cout << sqrt((arr[0] - arr[1]).norm2()) << "\n";
    //     return;
    // }
    sort(arr , arr+n);
    stack<Point> s;
    s.push(arr[0]) , s.push(arr[1]);
    for(int i = 2;i<n;i++){
        while(sz(s) >= 2){
            Point p1 = s.top();
            s.pop();
            Point p2 = s.top();
            if(cross(p2 , p1 , arr[i]) > 0){
                s.push(p1);
                break;
            }
        }
        s.push(arr[i]);
    }
    s.push(arr[n-2]);
    int len = sz(s);
    for(int i = n-3;i>=0;--i){
        while(sz(s) >= len){
            Point p1 = s.top();
            s.pop();
            Point p2 = s.top();
            if(cross(p2 , p1 , arr[i]) > 0){
                s.push(p1);
                break;
            }
        }
        s.push(arr[i]);
    }
    s.pop();
    vector<Point> hull;
    while(sz(s))hull.pb(s.top()) , s.pop();
    int sx = sz(hull);
    if(sx == 2){
        cout << sqrt((hull[1] - hull[0]).norm2()) << "\n";
        return;
    }
    for(int i =0 ;i<sx;i++)hull.pb(hull[i]);
    ll ans = 0;
    p = 0;
    for(int i =0 ;i<sz(hull)/2;i++){
       // edge is {hull[i] , hull[i+1]} 
       while(abs(cross(hull[i] , hull[i+1] , hull[p])) <= abs(cross(hull[i] , hull[i+1] , hull[p+1]))){
           ckmax(ans , max((hull[i] - hull[p]).norm2() , (hull[i+1] - hull[p]).norm2()));
            p++; 
            // p%=(sz(hull)/2);
       }
    }
    cout << sqrt(ans) << "\n";
}

int main(){
    setIO();
    cout << fixed << setprecision(12) << "\n";
    int t = 1;
    while(t--){
        solve();
    }
}
