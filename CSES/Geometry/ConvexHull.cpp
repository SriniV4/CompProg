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
int n;
void solve(){
    auto cross = [&](pi a , pi b , pi c){
       return (c.s - a.s) * (b.f - a.f) - (c.f - a.f) * (b.s - a.s); 
    };
    auto d2 = [&](pi a , pi b){
        return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
    };
    cin >> n;
    // return;
    vector<pi> points;
    int x = INT_MAX , y = INT_MAX;
    for(int i = 0;i<n;i++){
        int a , b;
        cin >> a >> b;
        if(x == INT_MAX)x= a , y = b;
        else {
            if(b < y || (b==y && a < x))points.pb({x , y}) , x = a , y = b;
            else points.pb({a , b});
        }
    }
    sort(all(points) , [&](auto& a , auto& b){
        auto exp = cross({x , y} , a , b);
        if(exp)
            return exp>0;
        return d2(a, {x , y}) < d2(b , {x , y});
    });
    stack<pi> p;
    p.push({x , y}) , p.push(points[0]);
    for(int i = 1;i<sz(points);i++){
        while(1){
            auto top = p.top();
            p.pop();
            auto sec = p.top();
            if(cross(sec , top , points[i]) >= 0){
                p.push(top);
                break;
            }
        }
        p.push(points[i]);
    }
    cout << sz(p) << "\n";
    while(sz(p))cout << p.top().f << " " << p.top().s << "\n" , p.pop();
} 

int main(){
    setIO();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}

