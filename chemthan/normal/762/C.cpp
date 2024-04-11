#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_
	#define cout cerr
#endif
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

const int maxn = 100000 + 10;
int n, m;
string a, b;
int prf[maxn];
int suf[maxn];

void solve() {
	cin >> a >> b;
	n = sz(a), m = sz(b);
	FOR(i, 0, n) {
		if (!i) {
			if (a[i] == b[0]) {
				prf[i] = 1;
			}
		}
		else {
			prf[i] = prf[i - 1];
			if (a[i] == b[prf[i - 1]]) {
				prf[i]++;
			}
		}
	}
	FORd(i, n, 0) {
		if (i == n - 1) {
			if (a[i] == b[m - 1]) {
				suf[i] = 1;
			}
		}
		else {
			suf[i] = suf[i + 1];
			if (a[i] == b[m - suf[i + 1] - 1]) {
				suf[i]++;
			}
		}
	}
	int best = 0, ix = 0, mx = 0;
	FORd(i, n, 0) {
		if (chkmax(best, min(m, prf[i] + mx))) {
			ix = i;
		}
		chkmax(mx, suf[i]);
	}
	if (chkmax(best, min(m, mx))) {
		ix = -1;
	}
	if (!best) {
		cout << "-\n";
		return;
	}
	int lptr = 0;
	FOR(i, 0, ix + 1) {
		if (a[i] == b[lptr]) {
			cout << a[i];
			lptr++;
		}
	}
	int rptr = m - 1;
	vector<char> tmp;
	FORd(i, n, ix + 1) {
		if (rptr < lptr) break;
		if (a[i] == b[rptr]) {
			tmp.pb(a[i]);
			rptr--;
		}
	}
	FORd(i, sz(tmp), 0) cout << tmp[i];
	cout << "\n";
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