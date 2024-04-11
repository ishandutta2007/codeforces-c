#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
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
template<typename X> void debug(X x) { cerr << x << "] "; }
template<typename X, typename ...Y> void debug(X x, Y... y) { cerr << x << " "; debug(y...); }
#define db(...) cerr << "[" << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#define endln cerr << "\n";
#define LIKELY(x)   (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))

void chemthan() {
  int n; cin >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i], a[i]--;
  auto solve = [&] () {
    vi nxt(n, n);
    vi prv(n, -1);
    {
      vii stk;
      FOR(i, 0, n) {
        while (sz(stk) && a[i] < stk.back().fi) stk.pop_back();
        if (sz(stk)) {
          prv[i] = stk.back().se;
        }
        stk.pb({a[i], i});
      }
    }
    {
      vii stk;
      FORd(i, n, 0) {
        while (sz(stk) && stk.back().fi < a[i]) stk.pop_back();
        if (sz(stk)) {
          nxt[i] = stk.back().se;
        }
        stk.pb({a[i], i});
      }
    }
    vi st(n << 1, n);
    auto _upd = [&] (int p, int v) {
      for (st[p += n] = v; 1 < p; ) p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]);
    };
    auto _query = [&] (int l, int r) {
      int res = n;
      for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmin(res, st[l++]);
        if (r & 1) chkmin(res, st[--r]);
      }
      return res;
    };
    auto add = [&] (int i) {
      if (nxt[i] < n) {
        _upd(a[i], nxt[i]);
      }
    };
    auto rem = [&] (int i, int ptr) {
      if (nxt[ptr] < n) {
        _upd(a[ptr], n);
      }
    };
    auto check = [&] (int i) {
      if (_query(a[i] + 1, n - 1) < prv[i]) {
        return 0;
      }
      return 1;
    };
    vi res(n);
    int ptr = 0;
    FOR(i, 0, n) {
      add(i);
      while (!check(i)) rem(i, ptr++);
      res[i] = i - ptr + 1;
    }
    return res;
  };
  auto res1 = solve();
  FOR(i, 0, n) a[i] = n - a[i] - 1;
  auto res2 = solve();
  long long res = 0;
  FOR(i, 0, n) res += min(res1[i], res2[i]);
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
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}