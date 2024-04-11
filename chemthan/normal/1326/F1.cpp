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
const ld EPS = 1e-6;
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
    vector<string> s(n);
    FOR(i, 0, n) cin >> s[i];
    vector<vi> a(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) a[i][j] = s[i][j] - '0';
    vi vals;
    FOR(msk, 0, 1 << n) {
        vals.pb(msk);
    }
    sort(all(vals), [&] (int u, int v) {
            return bitcount(u) < bitcount(v);
            }
        );
    vector<vi> g(1 << n);
    FOR(msk, 1, 1 << n) {
        FOR(i, 0, n) if (!bit(msk, i)) {
            g[msk].pb(i);
        }
    }
    vector<vector<vector<long long>>> dp(1 << n);
    vector<vector<long long>> f(1 << n);
    FOR(i, 0, n) {
        dp[1 << i].resize(1, vector<long long>(n));
        f[1 << i].resize(1);
        dp[1 << i][0][i] = 1;
        f[1 << i][0] = 1;
    }
    for (int msk : vals) {
        int k = bitcount(msk);
        for (int nxt : g[msk]) {
            int nmsk = msk | 1 << nxt;
            dp[nmsk].resize(1 << k, vector<long long>(n));
            f[nmsk].resize(1 << k);
        }
        FOR(sq, 0, 1 << k - 1) if (f[msk][sq]) {
            for (int lst : g[msk ^ (1 << n) - 1]) if (dp[msk][sq][lst]) {
                for (int nxt : g[msk]) {
                    int nmsk = msk | 1 << nxt;
                    int nsq = sq << 1 | a[lst][nxt];
                    dp[nmsk][nsq][nxt] += dp[msk][sq][lst];
                    f[nmsk][nsq] += dp[msk][sq][lst];
                }
            }
        }
        if (msk < (1 << n) - 1) {
            dp[msk].clear();
            dp[msk].shrink_to_fit();
            f[msk].clear();
            f[msk].shrink_to_fit();
        }
    }
    FOR(i, 0, sz(f.back())) cout << f.back()[i] << " \n"[i == sz(f.back()) - 1];
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