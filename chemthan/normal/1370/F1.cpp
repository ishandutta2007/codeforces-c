#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

struct Tree_t {
    vector<int> events;
    vector<int> sta;
    vector<int> lev;
    vector<int> tin;
    vector<int> tou;
    vector<int> idx;
    vector<vector<int>> par;
    int timer;
    vector<vector<int>> f;
    vector<int> mlg;

    void dfs(int u, int p, const vector<vector<int>>& adj) {
        idx[tin[u] = timer++] = u;
        sta[u] = events.size();
        events.push_back(tin[u]);
        for (int i = 1; i < (int) par.size(); i++) {
            par[i][u] = par[i - 1][par[i - 1][u]];
        }
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != p) {
                lev[v] = lev[u] + 1;
                par[0][v] = u;
                dfs(v, u, adj);
                events.push_back(tin[u]);
            }
        }
        tou[u] = timer - 1;
    }
    void build(const vector<vector<int>>& adj, int rt = 0) {
        events.clear();
        sta.resize(adj.size());
        lev.resize(adj.size());
        tin.resize(adj.size());
        tou.resize(adj.size());
        idx.resize(adj.size());
        par.resize(__lg(adj.size()) + 1);
        for (int i = 0; i < (int) par.size(); i++) {
            par[i].resize(adj.size());
            par[i][rt] = rt;
        }
        timer = lev[rt] = 0, dfs(rt, -1, adj);
        int logn = __lg(events.size()) + 1;
        f.resize(logn);
        for (int i = 0; i < logn; i++) {
            f[i].resize(events.size());
        }
        for (int i = 0; i < events.size(); i++) {
            f[0][i] = events[i];
        }
        for (int i = 1; i < logn; i++) {
            for (int j = 0; j + (1 << i - 1) < events.size(); j++) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
            }
        }
        mlg.resize(events.size());
        for (int i = 1; i < mlg.size(); i++) {
            mlg[i] = __lg(i);
        }
    }
    int rmq(int u, int v) {
        int l = u == v ? 0 : mlg[v - u];
        return min(f[l][u], f[l][v - (1 << l) + 1]);
    }
    int lca(int u, int v) {
        if (sta[u] > sta[v]) swap(u, v);
        return idx[rmq(sta[u], sta[v])];
    }
    int dist(int u, int v) {
        int a = lca(u, v);
        return lev[u] + lev[v] - lev[a] - lev[a];
    }
    int isanc(int p, int u) {
        return tin[p] <= tin[u] && tou[u] <= tou[p];
    }
    int go_up(int u, int k) {
        for (int i = (int) par.size() - 1; 0 <= i; i--) {
            if ((1 << i) <= k) {
                k -= 1 << i;
                u = par[i][u];
            }
        }
        return u;
    }
    int go_to(int u, int v, int k) {
        int a = lca(u, v);
        if (k <= lev[u] - lev[a]) {
            return go_up(u, k);
        }
        k -= lev[u] - lev[a];
        k = lev[v] - lev[a] - k;
        return go_up(v, k);
    }
} tree;

int mn;
int sec;
pi ask(vi v) {
    sort(all(v));
    cout << "? " << sz(v) << " ";
    FOR(i, 0, sz(v)) cout << v[i] + 1 << " \n"[i == sz(v) - 1];
    cout.flush();
    int x, y; cin >> x >> y; x--;
    chkmin(mn, y);
    return mp(x, y);
}

namespace TCD {
    vector<int> rem;
    vector<int> size;

    void dfs(const vector<vector<int>>& adj, int u, int p) {
        size[u] = 1;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != p && !rem[v]) {
                dfs(adj, v, u);
                size[u] += size[v];
            }
        }
    }
    int findcentroid(const vector<vector<int>>& adj, int u) {
        int p = -1;
        dfs(adj, u, -1);
        int cap = size[u] >> 1;
        while (1) {
            int found = 0;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (v != p && !rem[v] && cap < size[v]) {
                    p = u, u = v;
                    found = 1;
                    break;
                }
            }
            if (!found) return u;
        }
        assert(0);
    }
    int workspace(const vector<vector<int>>&, int);
    int divide(const vector<vector<int>>& adj, int u = 0, int depth = 0) {
        if (!depth) {
            rem.resize(adj.size());
            fill(rem.begin(), rem.end(), 0);
            size.resize(adj.size());
        }
        if (depth) {
            u = findcentroid(adj, u);
        }
        else {
            if (sz(adj[u]) == 1) {
                return u;
            }
        }
        rem[u] = 1;
        int nxt = workspace(adj, u);
        if (nxt == u) {
            int d = ask({u}).se;
            while (mn < d) {
                u = tree.go_to(u, sec, 1);
                d -= 2;
            }
            return u;
        }
        if (!depth) {
            sec = u;
        }
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!rem[v]) {
                if (tree.dist(u, nxt) == tree.dist(v, nxt) + 1) {
                    return divide(adj, v, depth + 1);
                }
            }
        }
        return u;
    }
    int workspace(const vector<vector<int>>& adj, int u) {
        vi vis(adj.size());
        vector<vi> vals;
        for (int t : adj[u]) if (!rem[t]) {
            vi ver;
            queue<int> que;
            que.push(t), vis[t] = 1;
            while (sz(que)) {
                int v = que.front(); que.pop();
                if (v != u) {
                    if (sec == -1 ||
                            tree.dist(u, sec) != tree.dist(u, v) + tree.dist(v, sec)) {
                        ver.pb(v);
                    }
                }
                for (int w : adj[v]) if (!rem[w] && !vis[w]) {
                    que.push(w), vis[w] = 1;
                }
            }
            if (sz(ver)) {
                vals.pb(ver);
            }
        }
        sort(all(vals), [&] (vi v1, vi v2) {
                return sz(v1) < sz(v2);
                }
            );
        vi ver;
        if (sec == -1) {
            vals.pop_back();
        }
        for (auto e : vals) {
            for (int v : e) {
                ver.pb(v);
            }
        }
        if (!sz(ver)) {
            return u;
        }
        auto r = ask(ver);
        if (mn < r.se) {
            return u;
        }
        return r.fi;
    }
}

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<vi> adj(n);
        FOR(i, 0, n - 1) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v), adj[v].pb(u);
        }
        tree.build(adj);
        mn = INF;
        sec = -1;
        vi v;
        FOR(u, 0, n) v.pb(u);
        int rt, d; tie(rt, d) = ask(v);
        int x = TCD::divide(adj, rt);
        v.clear();
        FOR(u, 0, n) {
            if (tree.dist(x, u) == d) {
                v.pb(u);
            }
        }
        int y = ask(v).fi;
        if (y < x) swap(x, y);
        cout << "! " << x + 1 << " " << y + 1 << "\n";
        cout.flush();
        string res; cin >> res;
    }
}

int main(int argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}