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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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

void chemthan() {
    int n; cin >> n;
    vector<vi> d(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) cin >> d[i][j];
    vector<tuple<int, int, int>> edges;
    FOR(i, 0, n) FOR(j, i + 1, n) edges.pb({d[i][j], i, j});
    sort(all(edges));
    vi dj(n);
    vector<vi> g(n);
    FOR(i, 0, n) dj[i] = i, g[i].pb(i);
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    vector<vi> adj(n);
    vi can(n, 1);

    int ptr = n;
    for (auto [w, u, v] : edges) {
        u = find(u), v = find(v);
        if (u ^ v) {
            dj[u] = ptr;
            dj[v] = ptr;
            dj.pb(ptr);
            g.pb(g[u]);
            g[ptr].insert(g[ptr].begin(), all(g[v]));
            can.pb(1);
            vi used(n);
            int mx = 0;
            for (int u : g[ptr]) {
                used[u] = 1;
                for (int v : g[ptr]) {
                    chkmax(mx, d[u][v]);
                }
            }
            for (int u : g[ptr]) {
                FOR(v, 0, n) if (!used[v]) {
                    if (d[u][v] < mx) {
                        can[ptr] = 0;
                    }
                }
            }
            adj.pb(vi());
            adj[ptr].pb(u);
            adj[ptr].pb(v);
            ptr++;
        }
    }
    vi tin(ptr), tou(ptr);
    vi rv(ptr);
    int timer = 0;
    function<void(int, int)> dfs = [&] (int u, int p) {
        rv[tin[u] = timer++] = u;
        for (int v : adj[u]) {
            if (v ^ p) {
                dfs(v, u);
            }
        }
        tou[u] = timer - 1;
    };
    dfs(ptr - 1, -1);
    vector<vi> dp(ptr + 1, vi(n + 1));
    dp[0][0] = 1;
    FOR(i, 0, ptr) {
        FOR(j, 0, n + 1) {
            int u = rv[i];
            if (j + 1 <= n) {
                if (can[u]) {
                    int nxt = tou[u] + 1;
                    addmod(dp[nxt][j + 1], dp[i][j]);
                }
            }
            if (tin[u] < tou[u]) {
                addmod(dp[i + 1][j], dp[i][j]);
            }
        }
    }
    FOR(i, 1, n + 1) {
        cout << dp[ptr][i] << " \n"[i == n];
    }
}

int32_t main(int32_t argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
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