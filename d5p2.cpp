#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int,int>;
#ifndef LOCAL
#define debug(...)
#endif
#define fi first
#define se second
#define pb push_back 
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define IMP cout << "IMPOSSIBLE" << '\n'
#define FOR(i,s,e) for (int i = (s); i < (e); ++i) 
#define F0R(i,e) FOR(i,0,e) 
#define ROF(i,s,e) for (int i = (e)-1; i >= (s); --i) 
#define R0F(i,e) ROF(i,0,e) 
#define printv(v,s,e) FOR(i,s,e+1) cout << v[i] << ' '; cout << '\n'
#define re(...) int __VA_ARGS__; read(__VA_ARGS__);
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T, class H> istream& operator>>(istream& in, pair<H, T>& a) {in >> a.fi >> a.se; return in;};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x: a) in >> x; return in;};
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

void solve() {
    int nseed = 20;
    string abcdef; cin >> abcdef;
    vector<array<int,3>> stor(nseed/2);
    F0R(i,nseed/2) {
        cin >> stor[i][0] >> stor[i][1];
    }
    vector<array<int,3>> ranges;
    for (auto [a,b,x]: stor) ranges.pb({a,a+b-1,0});
    debug(ranges);
    stor = ranges;
    vector<int> len = {17, 9, 40, 24, 20, 44, 41};
    for (int z: len) {
        string deez; cin >> deez >> deez;
        F0R(i,z) {
            re(e,s,r);
            F0R(j,sz(stor)) if (!stor[j][2]) {
                if ((s <= stor[j][0] && stor[j][1] < s+r)) {
                    stor[j][0] += e-s;
                    stor[j][1] += e-s;
                    stor[j][2] = 1;
                }
                else if ((s <= stor[j][1] && stor[j][1] < s+r)) {
                    stor.pb({stor[j][0], s-1,0});
                    stor[j][1] += e-s;
                    stor[j][0] = e;
                    stor[j][2] = 1;
                }
                else if ((s <= stor[j][0] && stor[j][0] < s+r)) {
                    stor.pb({s+r, stor[j][1], 0});
                    stor[j][0] += e-s;
                    stor[j][1] = s+r-1+e-s;
                    stor[j][2] = 1;
                }
            }
        }
        F0R(j,sz(stor)) stor[j][2] = 0;
        debug(stor);
    }
    debug(stor);
    int mn = 1E18;
    for (auto [a,b,c]: stor) mn = min(mn ,a);
    debug(mn);
}
signed main() {
    #ifdef LOCAL
    freopen("txt.in","r",stdin);
    freopen("txt.out","w",stdout);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}