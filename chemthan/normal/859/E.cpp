#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
const int MOD2 = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 4e5 + 5;
int n;
vi adj[maxn];
int deg[maxn];
int f[maxn];
int vis[maxn];
int dp[maxn][2];

int dj[maxn];
int size[maxn];
int edge[maxn];
void init() {
    FOR(i, 0, n + n) dj[i] = i, size[i] = 1, edge[i] = 0;
}
int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        dj[p] = q;
        size[q] += size[p];
        edge[q] += edge[p];
    }
    edge[q]++;
}

int dfs(int u, int can) {
    vis[u] = 1;
    int& res = dp[u][can];
    if (~res) return res;
    res = 1;
    vii vals;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        vals.pb(mp(dfs(v, 0), dfs(v, 1)));
        res = mult(res, dfs(v, 0));
    }
    vi prf(sz(vals), 1);
    vi suf(sz(vals), 1);
    FOR(i, 0, sz(vals)) {
        if (!i) prf[i] = vals[i].fi;
        else prf[i] = mult(prf[i - 1], vals[i].fi);
    }
    FORd(i, sz(vals), 0) {
        if (i == sz(vals) - 1) suf[i] = vals[i].fi;
        else suf[i] = mult(suf[i + 1], vals[i].fi);
    }
    if (can) {
        FOR(i, 0, sz(vals)) {
            int t = vals[i].se;
            if (i) t = mult(t, prf[i - 1]);
            if (i + 1 < sz(vals)) t = mult(t, suf[i + 1]);
            addmod(res, t);
        }
    }
    return res;
}

void solve() {
    cin >> n;
    init();
    FOR(i, 0, n) {
        int u, v; cin >> u >> v; u--, v--;
        if (u != v) {
            adj[v].pb(u);
            deg[u]++;
            join(u, v);
        }
        else {
            f[u] = 1;
        }
    }
    ms(dp, -1);
    int ans = 1;
    FOR(u, 0, n + n) if (!deg[u]) {
        ans = mult(ans, dfs(u, 1 - f[u]));
    }
    FOR(u, 0, n + n) if (dj[u] == u && !vis[u]) {
        if (size[u] == edge[u]) {
            ans = mult(ans, 2);
        }
    }
    cout << ans << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}