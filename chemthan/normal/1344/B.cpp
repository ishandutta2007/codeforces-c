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
    int n, m; cin >> n >> m;
    vector<string> a(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) {
        vi dj(m);
        FOR(j, 0, m) dj[j] = j;
        function<int(int)> find = [&] (int u) {
            return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
        };
        FOR(j, 0, m - 1) if (a[i][j] == '#' && a[i][j + 1] == '#') {
            dj[find(j)] = find(j + 1);
        }
        int c = 0;
        FOR(j, 0, m) if (a[i][j] == '#' && dj[j] == j) {
            c++;
        }
        if (1 < c) {
            cout << -1 << "\n";
            return;
        }
    }
    FOR(i, 0, m) {
        vi dj(n);
        FOR(j, 0, n) dj[j] = j;
        function<int(int)> find = [&] (int u) {
            return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
        };
        FOR(j, 0, n - 1) if (a[j][i] == '#' && a[j + 1][i] == '#') {
            dj[find(j)] = find(j + 1);
        }
        int c = 0;
        FOR(j, 0, n) if (a[j][i] == '#' && dj[j] == j) {
            c++;
        }
        if (1 < c) {
            cout << -1 << "\n";
            return;
        }
    }
    vi dj(n * m);
    FOR(i, 0, n * m) dj[i] = i;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] == '#') {
        FOR(dx, -1, 1 + 1) FOR(dy, -1, 1 + 1) {
            int ii = i + dx;
            int jj = j + dy;
            if (dx * dy == 0 && 0 <= ii && ii < n && 0 <= jj && jj < m && a[ii][jj] == '#') {
                dj[find(i * m + j)] = find(ii * m + jj);
            }
        }
    }
    int res = 0;
    FOR(i, 0, n) FOR(j, 0, m) {
        if (a[i][j] == '#' && dj[i * m + j] == i * m + j) {
            res++;
        }
    }
    set<int> sx, sy;
    FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] == '#') {
        sx.insert(i);
        sy.insert(j);
    }
    FOR(i, 0, n) FOR(j, 0, m) {
        if (!present(sx, i) && !present(sy, j)) {
            a[i][j] = '#';
        }
    }
    FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] == '#') {
        sx.insert(i);
        sy.insert(j);
    }
    if (sz(sx) != n || sz(sy) != m) {
        cout << -1 << "\n";
        return;
    }
    cout << res << "\n";
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