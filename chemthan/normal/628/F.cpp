#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

int n, b, q;

int calc(int l, int r, int k) {
	while (l % 5 != k) l++;
	while ((r + 5) % 5 != k) r--;
	if (l > r) return 0;
	return (r - l) / 5 + 1;
}

void solve() {
	scanf("%d%d%d", &n, &b, &q);
	vii v; v.pb(mp(0, 0)); v.pb(mp(b, n));
	FOR(i, 0, q) {
		int x, y; scanf("%d%d", &x, &y);
		v.pb(mp(x, y));
	}
	sort(all(v)); uni(v);
	FOR(i, 1, sz(v)) {
		if (v[i].se < v[i - 1].se || v[i].se - v[i - 1].se > v[i].fi - v[i - 1].fi) {
			puts("unfair");
			return;
		}
	}
	FOR(i, 0, 1 << 5) {
		int tot = 0;
		FOR(j, 1, sz(v)) {
			int d = 0;
			FOR(k, 0, 5) if (bit(i, k)) {
				d += calc(v[j - 1].fi + 1, v[j].fi, k);
			}
			tot += min(d, v[j].se - v[j - 1].se);
		}
		if (tot < bitcount(i) * n / 5) {
			puts("unfair");
			return;
		}
	}
	puts("fair");
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}