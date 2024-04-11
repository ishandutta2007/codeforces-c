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
const ld EPS = 1e-12;
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

#define double long double
const int maxn = 1e5 + 5;
int n;
int x[2];
int y[2];
double l[maxn];
double r[maxn];

void solve() {
	cin >> n;
	FOR(i, 0, 2) cin >> x[i] >> y[i];
	int ok = 1;
	FOR(i, 0, n) {
		int xx, yy, vx, vy; cin >> xx >> yy >> vx >> vy;
		double lx = 0, rx = 1e18;
		if (vx == 0) {
			if (xx <= x[0] || xx >= x[1]) {
				ok = 0;
			}
		}
		else if (vx > 0) {
			chkmax(lx, (double) (x[0] - xx) / vx);
			chkmin(rx, (double) (x[1] - xx) / vx);
		}
		else {
			chkmax(lx, (double) (x[1] - xx) / vx);
			chkmin(rx, (double) (x[0] - xx) / vx);
		}
		double ly = 0, ry = 1e18;
		if (vy == 0) {
			if (yy <= y[0] || yy >= y[1]) {
				ok = 0;
			}
		}
		else if (vy > 0) {
			chkmax(ly, (double) (y[0] - yy) / vy);
			chkmin(ry, (double) (y[1] - yy) / vy);
		}
		else {
			chkmax(ly, (double) (y[1] - yy) / vy);
			chkmin(ry, (double) (y[0] - yy) / vy);
		}
		l[i] = max(lx, ly);
		r[i] = min(rx, ry);
	}
	if (!ok) {
		cout << -1 << "\n";
		return;
	}
	double ans = 0;
	FOR(i, 0, n) {
		chkmax(ans, l[i]);
	}
	FOR(i, 0, n) {
		if (sign(ans, r[i]) >= 0) {
			cout << -1 << "\n";
			return;
		}
	}
	cout << prec(9) << ans << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
        JUDGE_ONLINE = 0;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    if (!JUDGE_ONLINE) {
    	//freopen("out.txt", "w", stdout);
    	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}