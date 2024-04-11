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
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 1000010;
const int maxe = 31;
int n, k;
int a[maxn];

struct Node {
	Node* nxt[2];
	int cnt;
	
	Node() {
		cnt = 0;
		nxt[0] = nxt[1] = 0;
	}
} *root;

void add(int n) {
	Node* cur = root;
	FORd(i, maxe, 0) {
		int l = bit(n, i);
		if (!cur->nxt[l]) cur->nxt[l] = new Node();
		cur = cur->nxt[l];
		cur->cnt++;
	}
}

ll query(int n) {
	ll res = 0;
	Node* cur = root;
	FORd(i, maxe, 0) {
		int l = bit(n, i);
		int x = bit(k, i);
		if (!x) {
			if (cur->nxt[!l]) {
				res += cur->nxt[!l]->cnt;
			}
			if (cur->nxt[l]) {
				cur = cur->nxt[l];
			}
			else {
				break;
			}
		}
		else {
			if (cur->nxt[!l]) {
				cur = cur->nxt[!l];
			}
			else {
				break;
			}
		}
	}
	return res;
}

void solve() {
	root = new Node();
	scanf("%d%d", &n, &k); k--;
	ll ans = 0;
	FOR(i, 1, n + 1) {
		scanf("%d", a + i);
		a[i] ^= a[i - 1];
		ans += a[i] > k ? 2 : 0;
		add(a[i]);
	}
	FOR(i, 1, n + 1) {
		ans += query(a[i]);
	}
	printf("%I64d\n", ans >> 1);
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