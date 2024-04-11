#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;

int n, K, a[MaxN];

int p[MaxN], s[MaxN];
int main() {
	int i;
	n = read(); K = read();
	for(i = 1; i <= n; i++) a[i] = read();
	if(K == 1) return printf("%d\n", *min_element(a + 1, a + n + 1)), 0;
	if(K == 2) {
		p[0] = s[n + 1] = 1e9;
		for(i = 1; i <= n; i++) p[i] = min(a[i], p[i - 1]);
		for(i = n; i; i--) s[i] = min(a[i], s[i + 1]);
		int ans = -1e9;
		for(i = 1; i < n; i++) cmax(ans, max(p[i], s[i + 1]));
		return printf("%d\n", ans), 0;
	}
	printf("%d", *max_element(a + 1, a + n + 1));
	return 0;
}