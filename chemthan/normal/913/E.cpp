#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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
const int MOD = 998244353;
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

struct cmp {
    bool operator() (const pair<string, pi>& s, const pair<string, pi>& t) {
        if (sz(s.fi) != sz(t.fi)) return sz(s.fi) > sz(t.fi);
        return s > t;
    }
};

int upd(string& s, string t) {
    return (sz(s) > sz(t) || (sz(s) == sz(t) && s > t)) ? s = t, 1 : 0;
}

void chemthan() {
    priority_queue<pair<string, pi>, vector<pair<string, pi> >, cmp> heap;
    static string dp[1 << 8][2];
    FOR(msk, 0, 1 << 8) dp[msk][0] = dp[msk][1] = "ffffffffffffffffffffffffffffffffffff";
    FOR(msk, 0, 1 << 8) {
        FOR(it, 0, 6) {
            string val[] = {"x", "!x", "y", "!y", "z", "!z"};
            int ok = 1;
            FOR(i, 0, 8) {
                int ar[] = {i / 4, i / 2 % 2, i % 2};
                int w = bit(msk, i);
                if (w != ar[it / 2] ^ it % 2) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                upd(dp[msk][0], val[it]);
                heap.push(mp(dp[msk][0], mp(msk, 0)));
            }
        }
    }
    while (sz(heap)) {
        string exp = heap.top().fi;
        int msk = heap.top().se.fi;
        int flag = heap.top().se.se;
        heap.pop();
        if (dp[msk][flag] != exp) continue;
        if (upd(dp[msk ^ (1 << 8) - 1][0], "!(" + dp[msk][flag] + ")")) {
            heap.push(mp(dp[msk ^ (1 << 8) - 1][0], mp(msk ^ (1 << 8) - 1, 0)));
        }
        FOR(msk2, 0, 1 << 8) FOR(flag2, 0, 2) if (dp[msk2][flag2] != "ffffffffffffffffffffffffffffffffffff") {
            if (upd(dp[msk | msk2][1], dp[msk][flag] + "|" + dp[msk2][flag2])) {
                heap.push(mp(dp[msk | msk2][1], mp(msk | msk2, 1)));
            }
            if (upd(dp[msk | msk2][1], dp[msk2][flag2] + "|" + dp[msk][flag])) {
                heap.push(mp(dp[msk | msk2][1], mp(msk | msk2, 1)));
            }
            string val = "";
            if (flag) {
                val += "(" + dp[msk][flag] + ")";
            }
            else {
                val += dp[msk][flag];
            }
            val += "&";
            if (flag2) {
                val += "(" + dp[msk2][flag2] + ")";
            }
            else {
                val += dp[msk2][flag2];
            }
            if (upd(dp[msk & msk2][0], val)) {
                heap.push(mp(dp[msk & msk2][0], mp(msk & msk2, 0)));
            }
            val = "";
            if (flag2) {
                val += "(" + dp[msk2][flag2] + ")";
            }
            else {
                val += dp[msk2][flag2];
            }
            val += "&";
            if (flag) {
                val += "(" + dp[msk][flag] + ")";
            }
            else {
                val += dp[msk][flag];
            }
            if (upd(dp[msk & msk2][0], val)) {
                heap.push(mp(dp[msk & msk2][0], mp(msk & msk2, 0)));
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        int msk = 0;
        FOR(i, 0, sz(s)) {
            if (s[i] == '1') {
                msk |= 1 << i;
            }
        }
        upd(dp[msk][0], dp[msk][1]);
        cout << dp[msk][0] << "\n";
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