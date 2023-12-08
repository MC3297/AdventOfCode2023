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
    string s, ln; cin >> s;
    getline(cin, ln);
    getline(cin, ln);
    map<string, pair<string,string>> adj;
    int n = 698;
    F0R(i,n) {
        getline(cin,ln);
        string start = ln.substr(0,3), l = ln.substr(7,3), r = ln.substr(12,3);
        adj[start] = {l,r};
    }
    vector<string> aa;
    for (auto [k,v]: adj) if (k[2] == 'A') aa.pb(k);
    debug(aa);
    vector<int> cycle;
    F0R(i,sz(aa)) {
        int ans = 0;
        while (1) {
            bool brk = 0;
            F0R(j,sz(s)) {
                if (s[j] == 'L') aa[i] = adj[aa[i]].fi;
                else aa[i] = adj[aa[i]].se;
                ans++;
                if (aa[i][2] == 'Z') {
                    brk = 1;
                    break;
                }
            }
            if (brk) break;
        }
        cycle.pb(ans);
    }
    
    debug(cycle);
    int ans = 1;
    for (int i: cycle) ans = lcm(ans, i);
    debug(ans);
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