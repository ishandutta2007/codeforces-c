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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
int ind[MAXN], dp[MAXN][2];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int x, int fa) {
	for(auto to : G[x]) {
		if(to == fa) continue;
		DFS(to, x);
		Ans = max(Ans, max(dp[x][0], dp[x][1]) + max(dp[to][0], dp[to][1]) + ind[x] - 2);
		Ans = max(Ans, dp[x][1] + dp[to][0] + 1);
		dp[x][0] = max(dp[x][0], max(dp[to][0], dp[to][1]));
		dp[x][1] = max(dp[x][1], dp[to][0]);
	}
	dp[x][0] = max(0, dp[x][0] + ind[x] - 1 - (fa != 0));
	Ans = max(Ans, ++dp[x][1]);
	Ans = max(Ans, dp[x][0] + (fa != 0));
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y); ind[x]++, ind[y]++;
		G[x].pb(y), G[y].pb(x);
	}
	DFS(1, 0);
	printf("%d\n", Ans);
	return 0;
}