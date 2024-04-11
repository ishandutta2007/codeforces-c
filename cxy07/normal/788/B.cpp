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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans, s[MAXN];
int self, d[MAXN], f[MAXN], cnt;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

bool unity(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return false;
	f[x] = y; return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m); cnt = n;
	for(int i = 1; i <= n; ++i) f[i] = i;
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y); s[i] = x;
		if(unity(x, y)) cnt--;
		if(x == y) self++;
		else d[x]++, d[y]++;
	} 
	for(int i = 1; i <= m; ++i) 
		if(find(s[i]) != find(s[1])) return puts("0"), 0;
	for(int i = 1; i <= n; ++i) Ans += (d[i] * (d[i] - 1)) >> 1;
	Ans += ((self * (self - 1)) >> 1) + self * (m - self);
	printf("%lld\n", Ans);
	return 0;
}