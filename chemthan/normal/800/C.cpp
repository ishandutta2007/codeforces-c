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

template<class T> pair<T, T> euclid(T a, T b) {
	if (!b) return make_pair(1, 0);
	pair<T, T> r = euclid(b, a % b);
	return make_pair(r.second, r.first - a / b * r.second);
}

template<class T> invert(T a, T p) {
	pair<T, T> r = euclid(a, p);
	return (r.fi % p + p) % p;
}

const int maxn = 2e5 + 5;
int n, m;
int f[maxn];
vi g[maxn];
vi dvs[maxn];
int dp[maxn];
int nxt[maxn];

int func(int k) {
	int& res = dp[k];
	if (~res) return res;
	res = 0;
	FOR(i, 0, sz(dvs[k])) {
		int nk = dvs[k][i];
		if (chkmax(res, func(nk))) {
			nxt[k] = nk;
		}
	}
	res += f[k];
	return res;
}

int calc(int x, int y, int p) {
	int d = __gcd(x, y);
	x /= d, y /= d, p /= __gcd(p, d);
	return (long long) x * invert(y, p) % p;
}

void solve() {
	FOR(i, 1, maxn) {
		for (int j = i + i; j < maxn; j += i) {
			dvs[j].pb(i);
		}
	}
	cin >> n >> m;
	set<int> st;
	FOR(i, 1, m + 1) {
		st.insert(i);
	}
	FOR(i, 0, n) {
		int x; cin >> x;
		if (!x) x = m;
		if (present(st, x)) {
			st.erase(x);
		}
	}
	FORall(it, st) {
		int x = __gcd(*it, m);
		f[x]++, g[x].pb(*it);
	}
	ms(dp, -1), ms(nxt, -1);
	pi ans;
	FOR(i, 1, m + 1) if (f[i]) {
		chkmax(ans, mp(func(i), i));
	}
	cout << ans.fi << "\n";
	vi v;
	int ptr = ans.se;
	while (ptr != -1) {
		FOR(j, 0, sz(g[ptr])) {
			v.pb(g[ptr][j]);
		}
		ptr = nxt[ptr];
	}
	reverse(all(v));
	vi vv = v;
	FOR(i, 1, sz(v)) vv[i] = calc(v[i], v[i - 1], m);
	FOR(i, 0, sz(vv)) {
		cout << vv[i] % m << " \n"[i == sz(vv) - 1];
	}
}

int main() {
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}