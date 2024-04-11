#include <bits/stdc++.h>

using namespace std; 

template <class T>
inline void read(T &x) {
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
inline void putint(T x) {
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else {
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y) {
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}

template <class T>
inline T getAbs(const T &x) {
	return x < 0 ? -x : x; 
}

using std::cerr; 
using std::cout; 
typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
//	freopen("a.out", "w", stdout);  
#endif

	int T; 
	read(T); 

	while (T--) {
		int n; 
		static int a[400000 + 5]; 

		read(n); 
		for (int i = 1; i <= n; ++i) {
			read(a[i]); 
		}

		a[n + 1] = 0; 

		s64 sum = 0; 
		for (int i = 1; i <= n; ++i) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				sum += a[i] - max(a[i - 1], a[i + 1]); 
				a[i] = max(a[i - 1], a[i + 1]); 
			}
		}
		
		for (int i = 1; i <= n; ++i) {
			sum += max(0, a[i] - a[i - 1]); 
			sum += max(0, a[i] - a[i + 1]); 
		}

		printf("%lld\n", sum); 
	}

	return 0; 
}