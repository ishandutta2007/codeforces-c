#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
// #define int ll
// #define db ld

using tii = tuple<int, int>; using ti3 = tuple<int, int, int>; using ti4 = tuple<int, int, int, int>;
#define mt(...) make_tuple(__VA_ARGS__)
#define X(x) get<0>(x)
#define Y(x) get<1>(x)
#define Z(x) get<2>(x)
#define W(x) get<3>(x)

using vi = vector<int>; using vii = vector<tii>; using vi3 = vector<ti3>; using vi4 = vector<ti4>;
using vvi = vector<vi>; using vvii = vector<vii>; using vvi3 = vector<vi3>; using vvi4 = vector<vi4>;
#define pf(...) emplace_front(__VA_ARGS__)
#define pb(...) emplace_back(__VA_ARGS__)

#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)
#define y0 kehaixing
#define y1 yigeiwoligiaogiao
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
int lowbit(int x) { return x & -x; }
template<class T, class U> void chkmx(T &x, U y) { if(y > x) x = y; }
template<class T, class U> void chkmn(T &x, U y) { if(y < x) x = y; }

// FASTIO
namespace fastio {
// #define fread_io
#ifdef fread_io
char buf[1 << 16], *st, *ed, wbuf[1 << 16], *wst = wbuf, *wed = wbuf + (1 << 16);
char gc() { return st == ed && (ed = (st = buf) + fread(buf, 1, 1 << 16, stdin), st == ed) ? -1 : *st++; }
__attribute__((destructor)) void flush() { fwrite(wbuf, 1, wst - wbuf, stdout), wst = wbuf; }
void pc(char x) { wst == wed && (flush(), 0), *wst++ = x; }
#else
char gc() { return getchar(); } void pc(char x) { putchar(x); }
#endif
#define notspace(x) (!isspace(x) && ~(x))
template<class T = int> T read() {
  T x = 0; char c = gc(); bool ne = false;
  while(!isdigit(c)) ne |= c == '-', c = gc();
  while(isdigit(c)) x = 10 * x + (c ^ 48), c = gc();
  return ne ? -x : x;
}
int reads(char *s) {
  int n = 0; char c = gc();
  while(!notspace(c)) c = gc();
  while(notspace(c)) s[n++] = c, c = gc();
  return s[n] = 0, n;
}
template<class T> void prt(T x) {
  x < 0 && (pc('-'), x = -x);
  x > 9 && (prt(x / 10), 0);
  pc(x % 10 ^ 48);
}
void prts(const char *s, int n = INT_MAX) { while(n-- && *s) pc(*s++); }
} using fastio::gc; using fastio::pc;
using fastio::read; using fastio::reads; using fastio::prt; using fastio::prts;

// MATH
constexpr int P = 0;
constexpr ll lnf = 0x3f3f3f3f3f3f3f3f;
#ifdef int
constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#else
constexpr int inf = 0x3f3f3f3f;
#endif

int gcd(int x, int y) { return __gcd(x, y); }
int exgcd(int a, int b, int &x, int &y) {
  if(!b) return x = 1, y = 0, a;
  int d = exgcd(b, a % b, y, x);
  return y -= a / b * x, d;
}
int qpow(int x, int y = P - 2, int p = P) {
  int res = 1;
  while(y) {
    if(y & 1) res = (ll)res * x % p;
    x = (ll)x * x % p;
    y >>= 1;
  } return res;
}
int inv(int a, int p = P) {
  int x, y, d = exgcd(a, p, x, y);
  if(d != 1) return -1;
  return x < 0 ? x + p : x;
}

namespace modint {
  void addto(int &x, int y) { x += y, x >= P && (x -= P), x < 0 && (x += P); }
  int add(int x, int y) { return x < 0 && (x += P), x += y, x >= P ? x - P : x < 0 ? x + P : x; }
  int add0(int x) { return x < 0 ? x + P : x; }
}
// using namespace modint;

template<int N, int p = P> struct fc_t {
  int iv[N], fc[N], ifc[N];
  fc_t() {
    iv[1] = 1; REP(i, 2, N - 1) iv[i] = (ll)iv[p % i] * (p - p / i) % p;
    fc[0] = ifc[0] = 1; REP(i, 1, N - 1) fc[i] = (ll)fc[i - 1] * i % p, ifc[i] = (ll)ifc[i - 1] * iv[i] % p;
  }
  int operator()(int n, int m) {
    if(m < 0 || m > n) return 0;
    return (ll)fc[n] * ifc[m] % p * ifc[n - m] % p;
  }
};
#define fc_init(...) fc_t<__VA_ARGS__> comb; int *iv = comb.iv, *fc = comb.fc, *ifc = comb.ifc
template<int N, int p = P> struct comb_t {
  int comb[N][N];
  comb_t() {
    comb[0][0] = 1;
    REP(i, 1, N - 1) REP(j, 0, i) comb[i][j] = ((j ? comb[i - 1][j - 1] : 0) + comb[i - 1][j]) % p;
  }
};
#define comb_init(...) comb_t<__VA_ARGS__> _comb; auto comb = _comb.comb
} using namespace temp;

constexpr int N = 2e5 + 10, LOG_N = 20;

int n, m;
int a[N], b[N];
bool is[N];
struct ufset {
  int fa[N];
  int root(int x) { return fa[x] ? fa[x] = root(fa[x]) : x; }
  void mrg(int x, int y) {
    x = root(x), y = root(y);
    fa[x] = y;
  }
} ufs;
vi nei[N];

int fa[N], dep[N], dfn[N], nowdfn, mng[N];
void dfs(int x = 1) {
  dep[x] = dep[fa[x]] + 1;
  mng[dfn[x] = ++nowdfn] = x;
  for(int y : nei[x]) if(y != fa[x]) fa[y] = x, dfs(y);
}
struct stable {
  int mn[LOG_N][N], lg[N];
  static bool cmp(int x, int y) { return dep[x] < dep[y]; }
  void init() {
    REP(i, 2, n) lg[i] = lg[i >> 1] + 1;
    REP(i, 1, n) mn[0][i] = fa[mng[i]];
    REP(i, 1, LOG_N - 1) REP(j, 1, n - (1 << i) + 1) mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)], cmp);
  }
  int lca(int x, int y) {
    if(x == y) return x;
    int l = dfn[x], r = dfn[y];
    if(l > r) swap(l, r); ++l;
    int lg0 = lg[r - l + 1];
    return min(mn[lg0][l], mn[lg0][r - (1 << lg0) + 1], cmp);
  }
} st; int lca(int x, int y) { return st.lca(x, y); }

int d[N];

int ans[N];
void dfs0(int x = 1, int now = 0) {
  now += d[x];
  if(now) ans[x] = 0;
  else ans[x] = 1;
  for(int y : nei[x]) if(y != fa[x]) dfs0(y, now);
}

void mian() {
  n = read(), m = read();
  REP(i, 1, m) a[i] = read(), b[i] = read();
  REP(i, 1, m) {
    if(ufs.root(a[i]) != ufs.root(b[i])) {
      is[i] = true;
      ufs.mrg(a[i], b[i]);
      nei[a[i]].pb(b[i]), nei[b[i]].pb(a[i]);
    }
  }
  dfs(), st.init();
  static vi son[N];
  REP(i, 1, n) for(int x : nei[i]) if(x != fa[i]) son[i].pb(x);
  REP(i, 1, m) if(!is[i]) {
    int x = a[i], y = b[i], z = lca(x, y);
    if(y == z) swap(x, y);
    if(x != z && y != z) {
      ++d[1], --d[x], --d[y];
    } else {
      auto fd = *--upper_bound(ALL(son[x]), y, [&](int a, int b) { return dfn[a] < dfn[b]; });
      ++d[fd], --d[y];
    }
  }
  dfs0();
  REP(i, 1, n) prt(ans[i]);
  pc('\n');
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  // freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
  int t = 1;
  // t = read();
  while(t--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (db)clock() / CLOCKS_PER_SEC);
  return 0;
}