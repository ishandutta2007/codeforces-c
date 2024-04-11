#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 5010;
int n;
int a[maxn];
int b[maxn];
vii v;

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {scanf("%d%d", a + i, b + i); v.push_back(make_pair(a[i], b[i]));}
	sort(v.begin(), v.end());
	int ans = 0;
	FOR(i, 0, n) {
		int p = min(v[i].first, v[i].second);
		int q = max(v[i].first, v[i].second);
		if (p >= ans) ans = p;
		else ans = q;
	}
	printf("%d", ans);
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}