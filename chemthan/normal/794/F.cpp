#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

const int maxn = 1e5 + 5;
int n, q;
int a[maxn][10];
long long st[maxn << 2][10];
int to[maxn << 2][10];

void build(int p, int L, int R) {
    FOR(i, 0, 10) {
        to[p][i] = i;
    }
    if (L == R) {
        FOR(i, 0, 10) {
            st[p][i] = a[L][i];
        }
        return;
    }
    build(p << 1, L, L + R >> 1);
    build(p << 1 | 1, (L + R >> 1) + 1, R);
    FOR(i, 0, 10) {
        st[p][i] = st[p << 1][i] + st[p << 1 | 1][i];
    }
}
void pushdown(int p, int L, int R) {
    long long tmp[10] = {};
    FOR(i, 0, 10) {
        int j = to[p][i];
        tmp[j] += st[p][i];
    }
    FOR(i, 0, 10) {
        st[p][i] = tmp[i];
    }
    if (L < R) {
        int ix = p << 1;
        FOR(it, 0, 2) {
            FOR(i, 0, 10) {
                int j = to[ix][i];
                to[ix][i] = to[p][j];
            }
            ix++;
        }
    }
    FOR(i, 0, 10) {
        to[p][i] = i;
    }
}
void upd(int p, int l, int r, int L, int R, int x, int y) {
    pushdown(p, L, R);
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
        to[p][x] = y;
        pushdown(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, x, y);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, x, y);
    FOR(i, 0, 10) {
        st[p][i] = st[p << 1][i] + st[p << 1 | 1][i];
    }
}
long long query(int p, int l, int r, int L, int R) {
    pushdown(p, L, R);
    if (l > R || r < L) return 0;
    if (l <= L && r >= R) {
        long long res = 0;
        FOR(i, 0, 10) {
            res += i * st[p][i];
        }
        return res;
    }
    return query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
}

void solve() {
    cin >> n >> q;
    FOR(i, 0, n) {
        int x; cin >> x;
        int p = 1;
        while (x) {
            a[i][x % 10] += p;
            x /= 10, p *= 10;
        }
    }
    build(1, 0, n - 1);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x, y; cin >> l >> r >> x >> y; l--, r--;
            if (x != y) {
                upd(1, l, r, 0, n - 1, x, y);
            }
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            cout << query(1, l, r, 0, n - 1) << "\n";
        }
    }
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}