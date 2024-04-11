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
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

void solve() {
	ll n; scanf("%I64d", &n);
	if (n == 0) {
		printf("%d %d", 0, 0);
		return;
	}
	ll l = 0, r = 600000000LL;
	while (l < r) {
		ll m = (l + r + 1) >> 1;
		if (3 * m * (m - 1) + 1 < n) l = m; else r = m - 1;
	}
	ll d = n - 3 * l * (l - 1);
	if (d < l) {
		printf("%I64d %I64d", 2 * l - d, 2 * d);
	}
	else if (d < 2 * l) {
		d -= l;
		printf("%I64d %I64d", l - 2 * d, 2 * l);
	}
	else if (d < 3 * l) {
		d -= 2 * l;
		printf("%I64d %I64d", -l - d, 2 * l - 2 * d);
	}
	else if (d < 4 * l) {
		d -= 3 * l;
		printf("%I64d %I64d", -2 * l + d, -2 * d);
	}
	else if (d < 5 * l) {
		d -= 4 * l;
		printf("%I64d %I64d", -l + 2 * d, -2 * l);
	}
	else {
		d -= 5 * l;
		printf("%I64d %I64d", l + d, -2 * l + 2 * d);
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}