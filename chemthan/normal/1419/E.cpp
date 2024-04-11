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
    auto solve = [&] (int k) {
        int n = 3;
        vi vals({1, 3, 2, 6, 4, 5, 7});
        while (n < k) {
            vi nvals;
            FOR(i, 0, sz(vals)) {
                nvals.pb(vals[i]);
                nvals.pb(vals[i] + (1 << n));
            }
            swap(nvals[2], nvals[3]);
            nvals.insert(nvals.begin() + 2, 1 << n);
            vals = nvals;
            n++;
        }
        FOR(i, 0, sz(vals)) {
            int j = (i + 1) % sz(vals);
            assert(vals[i] & vals[j]);
        }
        return vals;
    };
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        int nn = n;
        vi dvs;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                dvs.pb(i);
                dvs.pb(n / i);
            }
        }
        sort(all(dvs)), uni(dvs);
        dvs.erase(dvs.begin());
        map<int, int> hs;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                hs[i]++;
                n /= i;
            }
        }
        if (1 < n) {
            hs[n]++;
        }
        vi vals;
        for (auto e : hs) {
            vals.pb(e.fi);
        }
        if (sz(vals) == 1) {
            FOR(i, 0, sz(dvs)) cout << dvs[i] << " \n"[i == sz(dvs) - 1];
            cout << 0 << "\n";
            continue;
        }
        else if (sz(vals) == 2) {
            int a = vals[0];
            int b = vals[1];
            if (a * b == nn) {
                cout << a << " " << a * b << " " << b << "\n";
                cout << 1 << "\n";
                continue;
            }
            if (nn % ((long long) a * a * b)) {
                swap(a, b);
            }
            vi res({a, a * b, b, a * a * b});
            map<int, int> used;
            for (int x : res) used[x] = 1;
            vi nres;
            for (int x : res) {
                nres.pb(x);
                for (int y : dvs) {
                    if (!used[y] && y % x == 0) {
                        used[y] = 1;
                        nres.pb(y);
                    }
                }
            }
            res = nres;
            FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
            cout << 0 << "\n";
            continue;
        }
        auto v = solve(sz(vals));
        map<int, int> used;
        vi res;
        for (int msk : v) {
            int t = 1;
            FOR(i, 0, sz(vals)) if (bit(msk, i)) {
                t *= vals[i];
            }
            res.pb(t);
            used[t] = 1;
        }
        vi nres;
        for (int x : res) {
            nres.pb(x);
            for (int y : dvs) {
                if (!used[y] && y % x == 0) {
                    used[y] = 1;
                    nres.pb(y);
                }
            }
        }
        res = nres;
        FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
        cout << 0 << "\n";
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