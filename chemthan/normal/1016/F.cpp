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

template<class T> struct SegmenTree {
    static const int maxn = 3e5 + 5;
    T st[maxn << 2];
    T lz[maxn << 2];
    void upd(int p, int i, int L, int R, T val) {
        if (i < L || R < i) return;
        if (L == R) {
            st[p] = val;
            return;
        }
        upd(p << 1, i, L, L + R >> 1, val);
        upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }
    T query(int p, int l, int r, int L, int R) {
        if (r < L || R < l) return -LINF;
        if (l <= L && R <= r) return st[p];
        return max(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
};
SegmenTree<long long> seg[2];

const int maxn = 3e5 + 5;
int n, m;
vii adj[maxn];
long long a[maxn];
long long b[maxn];
int idx[maxn];

void dfs(int u, int p, long long d[]) {
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v != p) {
            d[v] = d[u] + w;
            dfs(v, u, d);
        }
    }
}

void chemthan() {
    cin >> n >> m;
    FOR(i, 0, n - 1) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    dfs(0, -1, a), dfs(n - 1, -1, b);
    vi ver; FOR(i, 0, n) ver.pb(i);
    sort(all(ver), [&] (int u, int v) {
            return mp(a[u] - b[u], u) < mp(a[v] - b[v], v);
            }
        );
    FOR(i, 0, n) {
        idx[ver[i]] = i;
    }
    FOR(u, 0, n) {
        seg[0].upd(1, idx[u], 0, n - 1, a[u]);
        seg[1].upd(1, idx[u], 0, n - 1, b[u]);
    }
    long long mx = 0;
    FOR(u, 0, n) {
        for (pi e : adj[u]) {
            int v = e.fi;
            seg[0].upd(1, idx[v], 0, n - 1, -LINF);
            seg[1].upd(1, idx[v], 0, n - 1, -LINF);
        }
        long long t1 = a[u] + seg[1].query(1, idx[u] + 1, n - 1, 0, n - 1);
        long long t2 = b[u] + seg[0].query(1, 0, idx[u] - 1, 0, n - 1);
        chkmax(mx, max(t1, t2));
        for (pi e : adj[u]) {
            int v = e.fi;
            seg[0].upd(1, idx[v], 0, n - 1, a[v]);
            seg[1].upd(1, idx[v], 0, n - 1, b[v]);
        }
    }
    FOR(i, 0, m) {
        int x; cin >> x;
        cout << min(a[n - 1], mx + x) << "\n";
    }
}

int main(int argc, char* argv[]) {
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