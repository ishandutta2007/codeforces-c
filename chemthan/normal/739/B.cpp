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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200000 + 10;
const int logn = 20;
int n;
int a[maxn];
vii adj[maxn];
int p[logn][maxn];
long long sum[logn][maxn];
int d[maxn];
int ans[maxn];

void dfs(int u) {
	FOR(i, 1, logn) {
		p[i][u] = p[i - 1][p[i - 1][u]];
		sum[i][u] = sum[i - 1][u] + sum[i - 1][p[i - 1][u]];
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		int w = adj[u][i].se;
		p[0][v] = u;
		sum[0][v] = w;
		dfs(v);
	}
}

int go(int u) {
	long long tot = 0;
	int st = u;
	FORd(i, logn, 0) {
		if (p[i][u] && tot + sum[i][u] <= a[st]) {
			tot += sum[i][u];
			u = p[i][u];
		}
	}
	if (tot + sum[0][u] <= a[st]) {
		u = p[0][u];
		tot += sum[0][u];
	}
	int ed = u;
	d[st]++;
	if (ed) {
		ed = p[0][ed];
		d[ed]--;
	}
}

int trace(int u) {
	ans[u] = d[u];
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		trace(v);
		ans[u] += ans[v];
	}
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, n - 1) {
		int u, w; cin >> u >> w; u--;
		adj[u].pb(mp(i + 1, w));
	}
	dfs(0);
	FOR(i, 1, n) go(i);
	trace(0);
	ans[0]++;
	FOR(i, 0, n) cout << ans[i] - 1 << " \n"[i == n - 1];
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