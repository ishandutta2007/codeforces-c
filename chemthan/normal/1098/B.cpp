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
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
template<class T> inline void addmod(T& a, T val, T p = MOD) {if ((a = (a + val)) >= p) a -= p;}
template<class T> inline void submod(T& a, T val, T p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

int ff(string& u, string& v) {
    int res = 0;
    FOR(i, 0, sz(u)) res += u[i] != v[i];
    return res;
}

int invert;

int calc(string a, string b, vector<string> s, int flag = 0) {
    int n = sz(s), m = sz(s[0]);
    string x, y, z, t;
    FOR(i, 0, m) x += a[i & 1];
    FOR(i, 0, m) y += a[(i ^ 1) & 1];
    FOR(i, 0, m) z += b[i & 1];
    FOR(i, 0, m) t += b[(i ^ 1) & 1];
    int res = 0;
    vector<string> vres;
    FOR(i, 0, n) {
        if (!(i & 1)) {
            int r1 = ff(s[i], x);
            int r2 = ff(s[i], y);
            res += min(r1, r2);
            if (flag) {
                if (r1 < r2) {
                    vres.pb(x);
                }
                else {
                    vres.pb(y);
                }
            }
        }
        else {
            int r1 = ff(s[i], z);
            int r2 = ff(s[i], t);
            res += min(r1, r2);
            if (flag) {
                if (r1 < r2) {
                    vres.pb(z);
                }
                else {
                    vres.pb(t);
                }
            }
        }
    }
    if (flag) {
        if (!invert) {
            FOR(i, 0, n) {
                FOR(j, 0, m) cout << vres[i][j];
                cout << "\n";
            }
        }
        else {
            FOR(i, 0, m) {
                FOR(j, 0, n) cout << vres[j][i];
                cout << "\n";
            }
        }
    }
    return res;
}

int solve(vector<string> a, int flag = 0) {
    string p = "AGCT";
    pi best = mp(INF, INF);
    FOR(msk, 0, 1 << 4) if (bitcount(msk) == 2) {
        string u, v;
        FOR(i, 0, 4) {
            if (bit(msk, i)) {
                u += p[i];
            }
            else {
                v += p[i];
            }
        }
        chkmin(best, mp(calc(u, v, a), msk));
    }
    int msk = best.se;
    string u, v;
    FOR(i, 0, 4) {
        if (bit(msk, i)) {
            u += p[i];
        }
        else {
            v += p[i];
        }
    }
    if (flag) {
        calc(u, v, a, 1);
    }
    return best.fi;
}

void chemthan() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (string& s : a) cin >> s;
    vector<string> b(m);
    FOR(j, 0, m) FOR(i, 0, n) b[j] += a[i][j];
    int x = solve(a);
    int y = solve(b);
    if (x < y) {
        solve(a, 1);
    }
    else {
        invert = 1;
        solve(b, 1);
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