#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n; bool a[MAXN];
char s[MAXN], t[MAXN];
int main() {
	read(n);
	scanf("\n%s", s + 1);
	scanf("\n%s", t + 1);
	int ans = 0, mns = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i] != t[i];
		ans += a[i];
		if (a[i] && a[i - 1] && s[i] != s[i - 1]) {
			a[i] = false;
			mns++;
		}
	}
	writeln(ans - mns);
	return 0;
}