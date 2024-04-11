#pragma GCC optimize(2)

//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'
#define y1 _y1

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, a[MAXN];
int s[2][MAXN], cnt[2], now = 1, pre;
int dp[2][MAXN], Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void Getid(int x) {
	for(int L = 1, R; L <= a[x]; L = R + 1) {
		R = (a[x] + L - 1) / ((a[x] + L - 1) / L);
		s[now][++cnt[now]] = (a[x] + L - 1) / L;
	} reverse(s[now] + 1, s[now] + cnt[now] + 1);
}

pii calc(int x, int t) {
	int cnt = (x + t - 1) / t, r;
	r = x / cnt; return mp(r, cnt - 1);
}

void solve() {
	read(n); dp[now][1] = 0; s[now][cnt[now] = 1] = 1; Ans = 0;
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1, pos; i <= n; ++i) {
		swap(now, pre); cnt[now] = 0; Getid(i);
		pos = 1;
		for(int j = 1, c, res; j <= cnt[now]; ++j) {
			tie(res, c) = calc(a[i], s[now][j]);
			while(pos <= cnt[pre] && s[pre][pos] <= res) ++pos;
			dp[now][j] = (dp[pre][pos - 1] + c * i) % mod;
		}
		(Ans += dp[now][cnt[now]]) %= mod;
	}
	printf("%lld\n", Ans);
}

signed main () {
#ifdef FILE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}