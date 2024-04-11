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
    int k, m; cin >> k >> m;
    set<string> res;
    FOR(i, 0, 5e4) {
        int j = abs(i - k);
        auto check = [&] (int u, int v) {
            int uu = i / u;
            int vv = j / v;
            int res =  (int) (to_string(u) + to_string(uu) + to_string(v) + to_string(vv)).size();
            if (uu <= 1) res--;
            if (vv <= 1) res--;
            return res;
        };
        auto cc = [&] (int u, int uu, int v, int vv) {
            int k = 8 - sz(to_string(u)) - sz(to_string(uu)) - sz(to_string(v)) - sz(to_string(vv));
            if (uu == 1) k++;
            if (vv == 1) k++;
            FOR(msk, 0, 1 << k) {
                FOR(i1, 0, k + 1) FOR(i2, 0, k - i1 + 1) FOR(i3, 0, k - i1 - i2 + 1) FOR(i4, 0, k - i1 - i2 - i3 + 1) {
                    int i5 = k - i1 - i2 - i3 - i4;
                    vi vw;
                    FOR(i, 0, k) vw.pb(bit(msk, i));
                    string s;
                    FOR(j, 0, i1) {
                        s += char('0' + vw.back());
                        vw.pop_back();
                    }
                    s += to_string(u);
                    FOR(j, 0, i2) {
                        s += char('0' + vw.back());
                        vw.pop_back();
                    }
                    if (1 < uu) {
                        s += to_string(uu);
                    }
                    FOR(j, 0, i3) {
                        s += char('0' + vw.back());
                        vw.pop_back();
                    }
                    s += to_string(v);
                    FOR(j, 0, i4) {
                        s += char('0' + vw.back());
                        vw.pop_back();
                    }
                    if (1 < vv) {
                        s += to_string(vv);
                    }
                    FOR(j, 0, i5) {
                        s += char('0' + vw.back());
                        vw.pop_back();
                    }
                    res.insert(s);
                    if (sz(res) == m) {
                        for (auto e : res) {
                            cout << e << "\n";
                        }
                        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
                        exit(0);
                    }
                }
            }
        };
        for (int u = 1; u * u <= i; u++) {
            if (i % u == 0) {
                for (int v = 1; v * v <= j; v++) {
                    if (j % v == 0) {
                        int t = check(u, v);
                        if (t <= 8) {
                            int uu = i / u;
                            int vv = j / v;
                            FOR(msk, 0, 1 << 3) {
                                int ar[] = {u, uu, v, vv};
                                if (bit(msk, 0)) {
                                    if (ar[0] == ar[1]) {
                                        continue;
                                    }
                                    swap(ar[0], ar[1]);
                                }
                                if (bit(msk, 1)) {
                                    if (ar[2] == ar[3]) {
                                        continue;
                                    }
                                    swap(ar[2], ar[3]);
                                }
                                if (bit(msk, 2)) {
                                    if (ar[0] == ar[2] && ar[1] == ar[3]) {
                                        continue;
                                    }
                                    swap(ar[0], ar[2]);
                                    swap(ar[1], ar[3]);
                                }
                                cc(ar[0], ar[1], ar[2], ar[3]);
                                if (t < 8) {
                                    FOR(c, 1, 10) {
                                        FOR(i, 0, 4) if (c <= ar[i] % 10) {
                                            int t = ar[i];
                                            ar[i] = (ar[i] - c) * 10 + c;
                                            FOR(d, 1, 10) {
                                                FOR(j, i + 1, 4) if (d <= ar[j] % 10) {
                                                    int tt = ar[j];
                                                    ar[j] = (ar[j] - d) * 10 + d;
                                                    cc(ar[0], ar[1], ar[2], ar[3]);
                                                    ar[j] = tt;
                                                }
                                            }
                                            cc(ar[0], ar[1], ar[2], ar[3]);
                                            ar[i] = t;
                                        }
                                        FOR(i, 0, 4) if (ar[i] % 10 + c < 10) {
                                            int t = ar[i];
                                            ar[i] = (ar[i] + c) * 10 + c;
                                            cc(ar[0], ar[1], ar[2], ar[3]);
                                            ar[i] = t;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    db(sz(res)) endln;
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