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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-12;
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

template<const int mod, const int maxf>
struct NTT {
  int rts[maxf + 1];
  int bitrev[maxf];
  int iv[maxf + 1];

  int fpow(int a, int k) {
    if (!k) return 1;
    int res = a, tmp = a;
    k--;
    while (k) {
      if (k & 1) {
        res = (long long) res * tmp % mod;
      }
      tmp = (long long) tmp * tmp % mod;
      k >>= 1;
    }
    return res;
  }
  int prt() {
    vector<int> dvs;
    for (int i = 2; i * i < mod; i++) {
      if ((mod - 1) % i) continue;
      dvs.push_back(i);
      if (i * i != mod - 1) dvs.push_back((mod - 1) / i);
    }
    for (int i = 2; i < mod; i++) {
      int flag = 1;
      for (int j = 0; j < dvs.size(); j++) {
        if (fpow(i, dvs[j]) == 1) {
          flag = 0;
          break;
        }
      }
      if (flag) return i;
    }
    assert(0);
    return -1;
  }
  NTT() {
    int k = 0; while ((1 << k) < maxf) k++;
    bitrev[0] = 0;
    for (int i = 1; i < maxf; i++) {
      bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
    }
    int pw = fpow(prt(), (mod - 1) / maxf);
    rts[0] = 1;
    for (int i = 1; i <= maxf; i++) {
      rts[i] = (long long) rts[i - 1] * pw % mod;
    }
    for (int i = 1; i <= maxf; i <<= 1) {
      iv[i] = fpow(i, mod - 2);
    }
  }
  void dft(int a[], int n, int sign) {
    int d = 0; while ((1 << d) * n != maxf) d++;
    for (int i = 0; i < n; i++) {
      if (i < (bitrev[i] >> d)) {
        swap(a[i], a[bitrev[i] >> d]);
      }
    }
    for (int len = 2; len <= n; len <<= 1) {
      int delta = maxf / len * sign;
      for (int i = 0; i < n; i += len) {
        int *w = sign > 0 ? rts : rts + maxf;
        for (int k = 0; k + k < len; k++) {
          int &a1 = a[i + k + (len >> 1)], &a2 = a[i + k];
          int t = (long long) *w * a1 % mod;
          a1 = a2 - t;
          a2 = a2 + t;
          a1 += a1 < 0 ? mod : 0;
          a2 -= a2 >= mod ? mod : 0;
          w += delta;
        }
      }
    }
    if (sign < 0) {
      int in = iv[n];
      for (int i = 0; i < n; i++) {
        a[i] = (long long) a[i] * in % mod;
      }
    }
  }
  void multiply(int a[], int b[], int na, int nb, int c[]) {
    static int fa[maxf], fb[maxf];
    int n = na + nb - 1; while (n != (n & -n)) n += n & -n;
    for (int i = 0; i < n; i++) fa[i] = fb[i] = 0;
    for (int i = 0; i < na; i++) fa[i] = a[i];
    for (int i = 0; i < nb; i++) fb[i] = b[i];
    dft(fa, n, 1), dft(fb, n, 1);
    for (int i = 0; i < n; i++) fa[i] = (long long) fa[i] * fb[i] % mod;
    dft(fa, n, -1);
    for (int i = 0; i < n; i++) c[i] = fa[i];
  }
  vector<int> multiply(vector<int> a, vector<int> b) {
    static int fa[maxf], fb[maxf], fc[maxf];
    int na = a.size(), nb = b.size();
    for (int i = 0; i < na; i++) fa[i] = a[i];
    for (int i = 0; i < nb; i++) fb[i] = b[i];
    multiply(fa, fb, na, nb, fc);
    int k = na + nb - 1;
    vector<int> res(k);
    for (int i = 0; i < k; i++) res[i] = fc[i];
    return res;
  }
};

NTT<MOD, 1 << 20> ntt;

void chemthan() {
  int C = 1e6;
  vi fac(C, 1), inv_fac(C);
  FOR(i, 1, C) fac[i] = mult(fac[i - 1], i);
  FOR(i, 0, C) inv_fac[i] = inv(fac[i]);
  auto binom = [&] (int n, int k) {
    return _mult(fac[n], inv_fac[k], inv_fac[n - k]);
  };
  int test; cin >> test;
  while (test--) {
    int n; cin >> n;
    vi a(n + 1);
    FOR(i, 0, n + 1) a[i] = inv(mult(fac[i], fpow(2, i)));
    vi b(n + 1);
    vi c(n + 1);
    FOR(i, 0, n + 1) b[i] = inv_fac[2 * i];
    FOR(i, 0, n + 1) c[i] = inv_fac[2 * i + 1];
    if (n % 2 == 0) b = ntt.multiply(a, b);
    else c = ntt.multiply(a, c);
    int res = 0;
    FOR(u, 0, n / 4 + 1) {
      int t = _mult(fac[n - 2 * u], inv_fac[u]);
      int m = n - 4 * u;
      int k = m / 2;
      if (m % 2 == 0) {
        t = _mult(t, b[k]);
      }
      else {
        t = _mult(t, c[k]);
      }
      addmod(res, t);
    }
    cout << res << "\n";
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
  int test = 1;
  //cin >> test;
  FOR(it, 1, test + 1) {
    chemthan();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}