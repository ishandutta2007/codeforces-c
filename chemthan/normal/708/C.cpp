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
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 400000 + 10;
int n;
vi adj[maxn];
int size[maxn];
int id[maxn];
int ans[maxn];

void dfs(int u, int p = -1, int ii = 0) {
	size[u] = 1, id[u] = ii;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			dfs(v, u, ii);
			size[u] += size[v];
		}
	}
}

int findcenter(int u) {
	int p = -1; dfs(u);
	int cap = size[u] >> 1;
	while (1) {
		int found = 0;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i];
			if (v != p && size[v] > cap) {
				p = u, u = v;
				found = 1;
				break;
			}
		}
		if (!found) break;
	}
	return u;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	int cen = findcenter(0);
	vi t(sz(adj[cen]));
	FOR(i, 0, sz(adj[cen])) {
		int u = adj[cen][i];
		dfs(u, cen, i);
		t[i] = size[u];
	}
	vi pr(sz(adj[cen])), sf(sz(adj[cen]));
	FOR(i, 0, sz(adj[cen])) {
		if (!i) pr[i] = t[i];
		else pr[i] = max(pr[i - 1], t[i]);
	}
	FORd(i, sz(adj[cen]), 0) {
		if (i == sz(adj[cen]) - 1) sf[i] = t[i];
		else sf[i] = max(sf[i + 1], t[i]);
	}
	FOR(i, 0, n) {
		int ix = id[i], mx = 0;
		if (ix) chkmax(mx, pr[ix - 1]);
		if (ix < sz(adj[cen]) - 1) chkmax(mx, sf[ix + 1]);
		if (t[ix] == n - n / 2 || size[i] + mx >= n - n / 2) {
			ans[i] = 1;
		}
	}
	ans[cen] = 1;
	FOR(i, 0, n) printf("%d%c", ans[i], " \n"[i == n - 1]);
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