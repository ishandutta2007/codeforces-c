//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
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

const int MAXN = 2010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, mn[MAXN], cur, Ans;
int a[MAXN], l[MAXN], r[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	for(int i = 1; i <= n; ++i) read(l[i]), read(r[i]), read(a[i]);
	mn[n] = max(0ll, a[n] - (r[n] - l[n]) * k);
	for(int i = n - 1; i; --i) {
		if(r[i] < l[i + 1]) mn[i] = max(0ll, a[i] - (r[i] - l[i]) * k);
		else mn[i] = max(0ll, a[i] + mn[i + 1] - (r[i] - l[i]) * k);
	}
	if(*max_element(mn + 1, mn + n + 1) > k) return puts("-1"), 0;
	cur = k;
	for(int i = 1; i <= n; ++i) {
		if(cur < mn[i]) { Ans += cur; cur = k; }
		Ans += a[i]; a[i] -= cur; 
		cur = ((((a[i] + k - 1) / k * k) - a[i]) % k + k) % k; 
	}
	printf("%lld\n", Ans);
	return 0;
}