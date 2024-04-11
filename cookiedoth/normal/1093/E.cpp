/*

Code for problem E by savkinsd2089
Generated 15 Dec 2018 at 07.15 pm
The Moon is Waxing Gibbous (52% of Full)


  !











\_()_/
=_=
^_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int getChar(); 
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt( T x, char end = 0, int len = -1 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
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

inline void readWord( char *s ) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine( char *s ) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
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
inline void writeInt( T x, char end, int output_len ) {
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

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
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

struct fenwick {
	vector<int> t;
	int n;

	fenwick() {}

	void init(int _n) {
		n = _n;
		t.resize(n);
	}

	void update(int pos, int val) {
		while (pos < n) {
			t[pos] += val;
			pos = (pos | (pos + 1));
		}
	}

	int get(int r) {
		int res = 0;
		while (r >= 0) {
			res += t[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

const int mx = 2e5 + 228;
const int K = 700;
const int B = mx / K + 10;
int n, a[mx], b[mx], _b[mx], _a[mx], arr[mx];
fenwick f[mx];

void update(int pos, int from_val, int after_val) {
	int f_id = pos / K;
	f[f_id].update(from_val, -1);
	f[f_id].update(after_val, 1);
	arr[pos] = after_val;
}

void update(int x, int y) {
	int vx = b[x], vy = b[y];
	update(_a[vx], x, y);
	update(_a[vy], y, x);
	swap(b[x], b[y]);
	_b[vx] = y;
	_b[vy] = x;
}

int get_seg(int l2, int r2, int i) {
	return (l2 <= arr[i] && arr[i] <= r2);
}

int get_seg(int l1, int r1, int l2, int r2) {
	int res = 0;
	for (int i = l1; i <= r1; ++i) {
		res += get_seg(l2, r2, i);
	}
	return res;
}

int get(int l1, int r1, int l2, int r2) {
	int res = 0;
	int block1 = l1 / K;
	int block2 = r1 / K;
	if (block1 == block2) {
		res = get_seg(l1, r1, l2, r2);
	}
	else {
		int up_l = (block1 + 1) * K - 1;
		int down_r = (block2) * K;
		res += get_seg(l1, up_l, l2, r2);
		res += get_seg(down_r, r1, l2, r2);
		for (int i = block1 + 1; i < block2; ++i) {
			res += f[i].get(l2, r2);
		}
	}
	return res;
}

signed main() {
	int q;
	n = readInt();
	q = readInt();
	for (int i = 0; i < n; ++i) {
		a[i] = readInt();
		a[i]--;
		_a[a[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		b[i] = readInt();
		b[i]--;
		_b[b[i]] = i;
	}

	for (int i = 0; i < n / K + 1; ++i) {
		f[i].init(n);
	}

	for (int i = 0; i < n; ++i) {
		int pos = i / K;
		f[pos].update(_b[a[i]], 1);
		arr[i] = _b[a[i]];
	}

	for (int i = 0; i < q; ++i) {
		int type;
		type = readInt();
		if (type == 1) {
			int l1, r1, l2, r2;
			l1 = readInt();
			r1 = readInt();
			l2 = readInt();
			r2 = readInt();
			l1--;
			r1--;
			l2--;
			r2--;
			cout << get(l1, r1, l2, r2) << "\n";
		}
		else {
			int x, y;
			x = readInt();
			y = readInt();
			x--;
			y--;
			update(x, y);
		}
	}
}