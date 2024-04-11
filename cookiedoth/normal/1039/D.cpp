/*

Code for problem D by cookiedoth
Generated 25 Mar 2020 at 12.08 PM


  !











\_()_/
^_^
~_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#pragma GCC optimize("Ofast")

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/** Fast input-output */

template <class T = int> inline T readInt();						
inline double readDouble();
inline int readUInt();					 
inline int readChar(); // first non-blank character
inline void readWord(char *s); 
inline bool readLine(char *s); // do not save '\n'
inline bool isEof();
inline int getChar(); 
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt(T x, char end = 0, int len = -1);
inline void writeChar(int x); 
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();

static struct buffer_flusher_t {
	~buffer_flusher_t() {
		flush();
	}
} buffer_flusher;

/** Read */

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
	if (buf_pos == buf_len) {
		buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (buf_pos == buf_len)
			return 1;
	}
	return 0;
}

inline int getChar() { 
	return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() { 
	return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		buf_pos++;
	return c == -1;
}

inline void skipBlanks() {
	while (!isEof() && buf[buf_pos] <= 32U)
		buf_pos++;
}

inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}

inline int readUInt() {
	int c = readChar(), x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	else if (c == '+')
		c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}

inline void readWord(char *s) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine(char *s) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
	if (write_buf_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
	write_buf[write_buf_pos++] = x;
}

inline void flush() {
	if (write_buf_pos) {
		fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
		fflush(stdout);
	}
}

template <class T> 
inline void writeInt(T x, char end, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble(double x, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}

// mdaaaa
const int mx = 5e5 + 228;
int n, p[mx], tin[mx], deg[mx], func[mx], timer, delta[mx];
vector<vector<int> > g;

void read() {
	n = readInt();
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		u = readInt();
		v = readInt();
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
}

void hang(int v, int pv, int last_ok) {
	if (v == 0 || deg[v] != 2) {
		tin[v] = timer++;
		func[v] = 0;
		delta[tin[v]] = func[pv] + 1;
		p[tin[v]] = last_ok;
		last_ok = tin[v];
	} else {
		func[v] = func[pv] + 1;
	}
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			hang(v1, v, last_ok);
		}
	}
}

void end_hang() {
	reverse(p, p + timer);
	reverse(delta, delta + timer);
	for (int i = 0; i < timer; ++i) {
		p[i] = timer - 1 - p[i];
	}
}

int val[mx], reset[mx];

int calc_dp(int len) {
	if (len == 0) {
		return n;
	}
	int res = 0;
	for (int i = 0; i < timer; ++i) {
		if (reset[i]) {
			res++;
			val[i] = -1;
		}
		val[i] += delta[i];
		while (val[i] > len) {
			val[i] -= (len + 1);
			res++;
		}
		if (val[p[i]] + val[i] >= len) {
			reset[p[i]]++;
		}
		if (val[i] >= val[p[i]]) {
			val[p[i]] = val[i];
		}
		val[i] = 0;
		reset[i] = 0;
	}
	return res;
}

int ans[mx];

void process(int l, int r, int exp_l, int exp_r) {
	if (exp_l == exp_r) {
		for (int i = l; i <= r; ++i) {
			ans[i] = exp_l;
		}
		return;
	}
	int mid = (l + r) >> 1;
	int res = calc_dp(mid);
	ans[mid] = res;
	if (l < mid) {
		process(l, mid - 1, res, exp_r);
	}
	if (mid < r) {
		process(mid + 1, r, exp_l, res);
	}
}

signed main() {
	fast_io();
	read();
	hang(0, 0, 0);
	end_hang();
	process(0, n - 1, 0, n);
	for (int i = 0; i < n; ++i) {
		writeInt(ans[i], '\n');
	}
}