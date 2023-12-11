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

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};//R, L, D, U
vector<string> grid;
array<int,4> good(int r, int c, int pr, int pc) {
    if (grid[r][c] == '|') {
        if (pr == r-1 && pc == c) return {r+1,c,r,c};
        if (pr == r+1 && pc == c) return {r-1,c,r,c};
    }
    if (grid[r][c] == '-') {
        if (pr == r && pc == c-1) return {r,c+1,r,c};
        if (pr == r && pc == c+1) return {r,c-1,r,c};
    }
    if (grid[r][c] == 'L') {
        if (pr == r-1 && pc == c) return {r,c+1,r,c};
        if (pr == r && pc == c+1) return {r-1,c,r,c};
    }
    if (grid[r][c] == 'J') {
        if (pr == r-1 && pc == c) return {r,c-1,r,c};
        if (pr == r && pc == c-1) return {r-1,c,r,c};
    }
    if (grid[r][c] == '7') {
        if (pr == r && pc == c-1) return {r+1,c,r,c};
        if (pr == r+1 && pc == c) return {r,c-1,r,c};
    }
    if (grid[r][c] == 'F') {
        if (pr == r && pc == c+1) return {r+1,c,r,c};
        if (pr == r+1 && pc == c) return {r,c+1,r,c};
    }
    return {-1,0,0,0};
}
int shoelace(vector<pii> v) {
    int ans = 0;
    F0R(i,sz(v)-1) {
        ans += v[i].fi*v[i+1].se-v[i].se*v[i+1].fi;
    }
    return abs(ans);//two times the area
    //2*shoelace - border + 2= 2*internal
}
void solve() {
    int n = 140;
    grid.resize(n); read(grid);
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m,-1));
    vector<vector<pii>> pa(n, vector<pii>(m));
    
    int sr, sc, er, ec;
    F0R(i,n) F0R(j,m) {
        if (grid[i][j] == 'S') sr = i, sc = j;
    }
    queue<array<int,4>> q;//cur, parent
    dist[sr][sc] = 0;
    debug(sr);
    debug(sc);

    F0R(i,4) {
        if (good(sr+dx[i],sc+dy[i],sr,sc)[0] != -1) {
            q.push({sr+dx[i],sc+dy[i],sr,sc});
        }
    }
    debug(q);
    vector<pii> endpts;
    while (sz(q)) {
        auto [r,c,pr,pc] = q.front();
        q.pop();
        if (!(0 <= r && r < n && 0 <= c && c < m)) continue;
        if (dist[r][c] != -1) {
            debug(dist[r][c]);
            er = r, ec = c;
            debug(er);
            debug(ec);
            endpts.pb({pr,pc});
            break;
        }
        dist[r][c] = dist[pr][pc]+1;
        pa[r][c] = {pr,pc};
        //| - L J 7 F . S
        q.push(good(r,c,pr,pc));
    }
    endpts.pb(pa[er][ec]);
    debug(endpts);
    vector<pii> v = {{er,ec}}, temp;
    pii cur = endpts[0];
    while (cur != make_pair(sr,sc)) {
        v.pb(cur);
        cur = pa[cur.fi][cur.se];
    }
    v.pb({sr,sc});
    cur = endpts[1];
    while (cur != make_pair(sr,sc)) {
        temp.pb(cur);
        cur = pa[cur.fi][cur.se];
    }
    R0F(i,sz(temp)) v.pb(temp[i]);
    v.pb({er,ec});
    //debug(v);
    //debug(sz(v));
    debug((shoelace(v)-(sz(v)-1)+2)/2);
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