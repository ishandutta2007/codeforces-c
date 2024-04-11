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
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}

void solve() {
	int n; cin>>n;
	if (n & 1) {
		FOR(i, 0, n >> 1) {
			cout<<n - (n - 2 * i - 1)<<" ";
		}
		cout<<n<<" ";
		FORd(i, n >> 1, 0) {
			cout<<n - (n - 2 * i - 1)<<" ";
		}
		FOR(i, 0, n >> 1) {
			cout<<n - (n - 2 * i - 2)<<" ";
		}
		FORd(i, n >> 1, 0) {
			cout<<n - (n - 2 * i - 2)<<" ";
		}
		cout<<n;
	}
	else {
		FOR(i, 0, n >> 1) {
			cout<<n - (n - 2 * i - 1)<<" ";
		}
		FORd(i, n >> 1, 0) {
			cout<<n - (n - 2 * i - 1)<<" ";
		}
		FOR(i, 0, (n >> 1) - 1) {
			cout<<n - (n - 2 * i - 2)<<" ";
		}
		cout<<n<<" ";
		FORd(i, (n >> 1) - 1, 0) {
			cout<<n - (n - 2 * i - 2)<<" ";
		}
		cout<<n;
	}
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