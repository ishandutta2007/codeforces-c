#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) (int) ((a).size())
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
int _mult(int x, int y) {return (long long) x * y % MOD;}
template<typename ...Y> int _mult(int x, Y... y) { return (long long) x * _mult(y...) % MOD; }
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
template<typename X> void debug(X x) { cerr << x << "] "; }
template<typename X, typename ...Y> void debug(X x, Y... y) { cerr << x << " "; debug(y...); }
#define db(...) cerr << "[" << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#define endln cerr << "\n";
#define LIKELY(x)   (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))

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

void chemthan() {
  int n, m; cin >> n >> m;
  vector<vi> adj(n);
  vi dj(n);
  FOR(i, 0, n) dj[i] = i;
  auto find = [&] (auto&& find, int u) -> int {
    return dj[u] == u ? dj[u] : dj[u] = find(find, dj[u]);
  };
  vii edges;
  FOR(i, 0, m) {
    int u, v; cin >> u >> v; u--, v--;
    if (find(find, u) != find(find, v)) {
      dj[find(find, u)] = find(find, v);
      adj[u].pb(v), adj[v].pb(u);
    }
    else {
      edges.pb({u, v});
    }
  }
  tree.build(adj);
  vi tin(n), tou(n), idx(n);
  int timer = 0;
  auto dfs = [&] (auto&& self, int u, int p) -> void {
    idx[tin[u] = timer++] = u;
    for (int v : adj[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    tou[u] = timer - 1;
  };
  auto is_parent = [&] (int p, int u) {
    return tin[p] <= tin[u] && tou[u] <= tou[p];
  };
  dfs(dfs, 0, -1);
  vi f(n + 1);
  for (auto [u, v] : edges) {
    if (tin[u] < tin[v]) swap(u, v);
    if (is_parent(v, u)) {
      f[tin[u]]++;
      f[tou[u] + 1]--;
      f[0]++;
      f[n]--;
      auto w = tree.go_to(u, v, tree.dist(u, v) - 1);
      f[tin[w]]--;
      f[tou[w] + 1]++;
    }
    else {
      f[tin[u]]++;
      f[tou[u] + 1]--;
      f[tin[v]]++;
      f[tou[v] + 1]--;
    }
  }
  FOR(i, 1, n + 1) f[i] += f[i - 1];
  string res(n, '1');
  FOR(i, 0, n) {
    if (f[i] < sz(edges)) {
      res[idx[i]] = '0';
    }
  }
  cout << res << "\n";
}

int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  int test = 1;
  //cin >> test;
  while (test--)
    chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}