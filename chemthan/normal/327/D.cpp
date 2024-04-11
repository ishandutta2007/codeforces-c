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

const int maxn = 500 + 10;
int n, m;
int a[maxn][maxn];
int vis[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pair<char, pi> > ans;

inline int inside(int u, int v) {
	if (!(u >= 0 && u < n)) return 0;
	if (!(v >= 0 && v < m)) return 0;
	return a[u][v] == '.';
}

void dfs(int u, int v) {
	vis[u][v] = 1;
	ans.pb(mp('B', mp(u, v)));
	FOR(i, 0, 4) {
		int nu = u + dx[i];
		int nv = v + dy[i];
		if (inside(nu, nv) && !vis[nu][nv]) {
			dfs(nu, nv);
			ans.pb(mp('R', mp(nu, nv)));
		}
	}
	ans.pb(mp('D', mp(u, v)));
}

void solve() {
	cin >> n >> m;
	FOR(i, 0, n) {
		string s; cin >> s;
		FOR(j, 0, m) a[i][j] = s[j];
	}
	FOR(i, 0, n) FOR(j, 0, m) if (!vis[i][j] && a[i][j] == '.') {
		dfs(i, j);
		ans.pb(mp('B', mp(i, j)));
	}
	cout << sz(ans) << "\n";
	FOR(i, 0, sz(ans)) cout << ans[i].fi << " " << ans[i].se.fi + 1 << " " << ans[i].se.se + 1 << "\n";
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