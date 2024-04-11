//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 50010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int r[MAXN][6], p[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool chk(int x) {
	for(int i = 1, c = 0; i <= n; ++i) {
		if(i == x) continue;
		c = 0;
		for(int j = 1; j <= 5; ++j) c += (r[x][j] < r[i][j]);
		if(c < 3) return false;
	}
	return true;
}

bool cmp(int x, int y) {
	int c = 0;
	for(int i = 1; i <= 5; ++i)
		c += (r[x][i] < r[y][i]);
	return c >= 3;
}

void solve() {
	read(n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= 5; ++j) read(r[i][j]);
	for(int i = 1; i <= n; ++i) p[i] = i;
	sort(p + 1, p + n + 1, cmp);
	if(chk(p[1])) printf("%d\n", p[1]);
	else puts("-1");
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}