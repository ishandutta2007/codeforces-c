#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int n, A, B, sum, a[MAXN];
bool cmp(int x, int y) {return x > y; }
int main() {
	read(n), read(A), read(B);
	for (int i = 1; i <= n; i++)
		read(a[i]), sum += a[i];
	sort(a + 2, a + n + 1, cmp);
	sum -= a[1] * A / B;
	if (sum <= 0){
		writeln(0);
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		sum -= a[i];
		if (sum <= 0) {
			writeln(i - 1);
			return 0;
		}
	}
	return 0;
}