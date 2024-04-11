#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

const int maxn = 1e6 + 5;
int n, m, k;
int f[maxn];
int g[maxn];
vi v1, v2;

int compare1(int i, int j) {
    if (f[i] != f[j]) return f[i] < f[j];
    return i < j;
}

int compare2(int i, int j) {
    if (g[i] != g[j]) return g[i] < g[j];
    return i < j;
}

int func(int mid) {
    vi vx1, vx2, v(n + mid);
    FOR(i, 0, n) vx1.pb(f[v1[i]]);
    FOR(i, 0, mid) vx2.pb(g[v2[m - i - 1]]);
    reverse(all(vx2));
    merge(all(vx1), all(vx2), v.begin());
    FOR(i, 0, sz(v)) {
        int t = i / k;
        if (v[i] < t) return 0;
    }
    return 1;
}

void solve() {
    cin >> n >> m >> k;
    FOR(i, 0, n) cin >> f[i];
    FOR(i, 0, m) cin >> g[i];
    FOR(i, 0, n) v1.pb(i);
    FOR(i, 0, m) v2.pb(i);
    sort(all(v1), compare1);
    sort(all(v2), compare2);
    int l = -1, r = m;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (func(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l << "\n";
    FOR(i, 0, l) {
        cout << v2[m - i - 1] + 1 << " \n"[i == l - 1];
    }
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}