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
 
int n = 140, m;
vector<string> grid(n);
bool emptyrow(int r) {
    F0R(j,m) if (grid[r][j] != '.') return 0;
    return 1;
}
bool emptycol(int c) {
    F0R(i,n) if (grid[i][c] != '.') return 0;
    return 1;
}
void solve() {
    read(grid);
    m = sz(grid[0]);
    vector<int> row(n,0), col(m,0);
    if (emptyrow(0)) row[0]++;
    if (emptycol(0)) col[0]++;
    FOR(i,1,n) row[i] = row[i-1] + emptyrow(i);
    FOR(j,1,m) col[j] = col[j-1] + emptycol(j);
    int ans = 0;
    vector<pii> pos;
    F0R(i,n) F0R(j,m) {
        if (grid[i][j] == '#') pos.pb({i,j});
    }
    debug(row);
    debug(col);
    F0R(l,sz(pos)) {
        FOR(r,l+1,sz(pos)) {
            auto [i,j] = pos[l];
            auto [a,b] = pos[r];
            if (grid[i][j] == grid[a][b] && grid[i][j] == '#') {
                int dist = abs(i-a) + abs(j-b);
                dist += row[max(i,a)] - row[min(i,a)];
                dist += col[max(j,b)] - col[min(j,b)];
                ans += dist;
            }
        }
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