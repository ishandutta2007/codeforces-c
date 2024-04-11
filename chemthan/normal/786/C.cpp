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
#define db(x) cout << #x << " = " << (x) << "\n";

const int maxn = 1e5 + 5;
int n;
int a[maxn];
int nxt[maxn];

int st[maxn << 2];
void upd(int p, int i, int L, int R, int val) {
	if (i < L || i > R) return;
	if (L == R) {
		st[p] += val;
		return;
	}
	upd(p << 1, i, L, L + R >> 1, val);
	upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
	st[p] = st[p << 1] + st[p << 1 | 1];
}
int query(int p, int L, int R, int k) {
	if (L == R) return L;
	if (st[p << 1] >= k) return query(p << 1, L, L + R >> 1, k);
	return query(p << 1 | 1, (L + R >> 1) + 1, R, k - st[p << 1]);
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i], a[i]--;
	static int lst[maxn] = {};
	fill_n(lst, n, -1), fill_n(nxt, n, n);
	FORd(i, n, 0) {
		if (~lst[a[i]]) {
			upd(1, lst[a[i]], 0, n, -1);
			nxt[i] = lst[a[i]];
		}
		upd(1, i, 0, n, 1);
		lst[a[i]] = i;
	}
	static vii g[maxn];
	static int ans[maxn];
	FOR(i, 1, n + 1) {
		g[0].pb(mp(i, 0));
	}
	FOR(k, 0, n) {
		FOR(i, 0, sz(g[k])) {
			int x = g[k][i].fi;
			int v = g[k][i].se;
			int nxt = query(1, 0, n, x + 1);
			if (nxt == n) {
				ans[x] = v + 1;
			}
			else {
				g[nxt].pb(mp(x, v + 1));
			}
		}
		upd(1, k, 0, n, -1);
		if (nxt[k] < n) {
			upd(1, nxt[k], 0, n, 1);
		}
	}
	FOR(i, 1, n + 1) {
		cout << ans[i] << " \n"[i == n];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}