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
int P = 0;
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
using namespace modint;
} using namespace temp;

constexpr int N = 2010;

int iv[N], fc[N], ifc[N];
int comb(int n, int m) {
  if(m < 0 || m > n) return 0;
  return (ll)fc[n] * ifc[m] % P * ifc[n - m] % P;
}

int n;
vi nei[N];

int dp[N][N], f[N][N];
void dfs(int x = 1, int fa = 0) {
  for(int y : nei[x]) if(y != fa) dfs(y, x);
  static int Leq[N][N], leQ[N][N];
  REP(i, 1, n) Leq[0][i] = leQ[SZ(nei[x]) + 1][i] = 1;
  REP(i, 1, SZ(nei[x])) {
    int y = nei[x][i - 1];
    if(y == fa) {
      REP(j, 1, n) Leq[i][j] = Leq[i - 1][j];
    } else {
      REP(j, 1, n) Leq[i][j] = (ll)Leq[i - 1][j] * f[y][j] % P;
    }
  }
  PER(i, SZ(nei[x]), 1) {
    int y = nei[x][i - 1];
    if(y == fa) {
      REP(j, 1, n) leQ[i][j] = leQ[i + 1][j];
    } else {
      REP(j, 1, n) leQ[i][j] = (ll)leQ[i + 1][j] * f[y][j] % P;
    }
  }
  REP(i, 1, n) dp[x][i] = Leq[SZ(nei[x])][i];
  if(x > 1) {
    REP(i, 1, SZ(nei[x])) {
      int y = nei[x][i - 1];
      if(y == fa) continue;
      static int leq[N];
      REP(j, 1, n) leq[j] = (ll)Leq[i - 1][j] * leQ[i + 1][j] % P;
      REP(j, 1, n) addto(leq[j], leq[j - 1]);
      REP(j, 1, n) addto(dp[x][j], (ll)leq[j - 1] * dp[y][j] % P);
    }
  }
  REP(i, 1, n) f[x][i] = add(dp[x][i], f[x][i - 1]);
}

void mian() {
  n = read(), P = read();
  #define p P
  iv[1] = 1; REP(i, 2, N - 1) iv[i] = (ll)iv[p % i] * (p - p / i) % p;
  fc[0] = ifc[0] = 1; REP(i, 1, N - 1) fc[i] = (ll)fc[i - 1] * i % p, ifc[i] = (ll)ifc[i - 1] * iv[i] % p;
  #undef p
  REP(i, 1, n - 1) {
    int x = read(), y = read();
    nei[x].pb(y), nei[y].pb(x);
  }
  dfs();
  static int ans[N];
  ans[1] = 1;
  REP(i, 2, n) {
    ans[i] = add(dp[1][i], -dp[1][i - 1]);
    REP(j, 1, i - 1) addto(ans[i], -(ll)comb(i - 1, j - 1) * ans[j] % P);
  }
  REP(i, 1, n - 1) prt(ans[i]), pc(" \n"[i == n - 1]);
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