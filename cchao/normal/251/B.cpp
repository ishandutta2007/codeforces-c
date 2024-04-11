//{{{
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BR putchar('\n')
#define MS0(ar) memset(ar, 0, sizeof(ar))
#define MS1(ar) memset(ar, -1, sizeof(ar))
#define F first
#define S second
#define MP make_pair
#define MT make_tuple
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef complex<double> CD;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<LL> VL;

void R(int &x) { scanf("%d", &x); }
void R(LL &x) { scanf("%lld", &x); }
void R(ULL &x) { scanf("%llu", &x); }
void R(double &x) { scanf("%lf", &x); }
void R(LD &x) { scanf("%Lf", &x); }

template <typename T> void R(T &t) { cin >> t; }
template <typename A, typename B> void R(pair<A, B> &x) {
  R(x.F);
  R(x.S);
}

template <typename T> void R(vector<T> &ar) {
  for (auto &it : ar)
    R(it);
}

template <typename T, typename... Args> void R(T &t, Args &... args) {
  R(t);
  R(args...);
}

void W(const char &c) { putchar(c); };
void W(const int &x) { printf("%d", x); }
void W(const LL &x) { printf("%lld", x); }
void W(const ULL &x) { printf("%llu", x); }
void W(const double &x) { printf("%lf", x); }
void W(const LD &x) { printf("%Lf", x); }

template <typename T> void W(const T &t) { cout << t; }
template <typename T> void W(const vector<T> &ar) {
  for (size_t i = 0; i < ar.size(); ++i) {
    W(ar[i]);
    putchar(" \n"[i + 1u == ar.size()]);
  }
}
template <typename T, typename... Args>
void W(const T &t, const Args &... args) {
  W(t);
  W(args...);
}
#define BR putchar('\n')

template <typename T> void Min(T &x, T v) { x = min(x, v); }
template <typename T> void Max(T &x, T v) { x = max(x, v); }
//}}}
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;

VI operator*(const VI &a, const VI &b) {
  VI c(a.size());
  REP(i, a.size())
    c[b[i]] = a[i];
  return c;
}

VI inv(const VI &a) {
  VI c(a.size());
  REP(i, a.size())
    c[a[i]] = i;
  return c;
}

bool operator==(const VI &a, const VI &b) {
  REP(i, a.size())
    if (a[i] != b[i])
      return false;
  return true;
}

int n, k;
VI q, s;
int f(const VI &q) {
  VI a(q.size());
  REP(i, a.size()) a[i] = i;
  int ret = 0;
  while (!(a == s)) {
    a = a * q;
    if (++ret > k)
      break;
  }
  return ret;
}


int main() {
  R(n, k);
  q.resize(n);
  s.resize(n);
  R(q, s);
  REP(i, n) q[i]--, s[i]--;
  if (is_sorted(ALL(s))) {
    puts("NO");
    return 0;
  }
  int ca = f(q), cb = f(inv(q));
  // printf("%d %d\n", ca, cb);
  bool ans = (ca <= k && ca % 2 == k % 2) || (cb <= k && cb % 2 == k % 2);
  if (ca == 1 && cb == 1)
    ans = k == 1;
  puts(ans ? "YES" : "NO");
  return 0;
}