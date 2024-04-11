//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 110;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
int dp[MAXN][MAXN][2];
pii s[MAXN];

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
	read(n);
	for(int i = 1; i <= n; ++i) 
		read(s[i].fst), read(s[i].scd);
	sort(s + 1, s + n + 1);
	s[0].fst = -INF;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= i; ++j) {
			for(int d = 0; d <= 1; ++d) {
				Ans = max(Ans, dp[i][j][d]);
				int R = d ? s[j].fst + s[j].scd : s[j].fst, Max = -INF, x, p;
				for(int k = i + 1; k <= n; ++k) {
					for(int b = 0; b <= 1; ++b) {
						int at = b ? s[k].fst + s[k].scd : s[k].fst;
						if(at > Max) Max = at, x = k, p = b;
						dp[k][x][p] = max(dp[k][x][p], dp[i][j][d] + min(at - R, s[k].scd) + Max - at);
					}
				}
			}
		}
	}
	printf("%d\n", Ans);
	return 0;
}