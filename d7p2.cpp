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


int typ(string s) {
    map<char,int> mp;
    int j = 0;
    for (char c: s) {
        if (c != 'J') mp[c]++;
        else j++;
    }
    //debug(mp);
    vector<int> a;
    for (auto [k,v]: mp) a.pb(v);
    sort(all(a));
    if (sz(a) == 0) a.pb(j);
    else a[sz(a)-1] += j;
    if (a == vector<int>({5})) return 6;
    if (a == vector<int>({1,4})) return 5;
    if (a == vector<int>({2,3})) return 4;
    if (a == vector<int>({1,1,3})) return 3;
    if (a == vector<int>({1,2,2})) return 2;
    if (a == vector<int>({1,1,1,2})) return 1;
    if (a == vector<int>({1,1,1,1,1})) return 0;
    debug(a);
    return -1;
}
vector<int> conv(string s) {
    vector<int> ans;
    for (char c: s) {
        if (c == 'A') ans.pb(14);
        else if (c == 'K') ans.pb(13);
        else if (c == 'Q') ans.pb(12);
        else if (c == 'J') ans.pb(1);
        else if (c == 'T') ans.pb(10);
        else ans.pb(c-'0');
    }
    return ans;
}
void solve() {
    int n = 1000;
    vector<pair<string,int>> stor(n); read(stor);
    sort(all(stor), [](pair<string,int>& a, pair<string,int>& b){
        if (typ(a.fi) == typ(b.fi)) {
            return conv(a.fi) < conv(b.fi);
        }
        else return typ(a.fi) < typ(b.fi);
    });
    //for (auto i: stor) cout << i << '\n';
    int ans = 0;
    F0R(i,n) {
        ans += (i+1) * stor[i].se;
    }
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