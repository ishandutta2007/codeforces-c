#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x)
{
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

using std::min; 
using std::max; 
using std::pair; 
using std::cin; 
using std::cout; 
using std::vector; 
typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 3510; 
const int INF = 0x3f3f3f3f; 

int n, m, K; 
int a[MaxN]; 

inline void solve()
{
	read(n), read(m), read(K); 
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]);
	}

	int len = n - m + 1; 
	static int b[MaxN], tot; 

	tot = 0; 
	for (int i = 1; i + len - 1 <= n; ++i)
	{
		b[i] = std::max(a[i], a[i + len - 1]); 
		++tot; 
	}

	int lst = std::max(0, (n - len) - K); 
	int can = std::min(lst + 1, tot); 

//	std::cout << lst << ' ' << can << '\n'; 

	int ans = 0; 
	for (int i = 1; i + can - 1 <= tot; ++i)
	{
		int cur = INF; 
		for (int j = i; j <= i + can - 1; ++j)
			tense(cur, b[j]); 
		relax(ans, cur); 
	}

	printf("%d\n", ans); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	int orzczk; 
	read(orzczk); 
	while (orzczk--)
		solve(); 

	return 0; 
}