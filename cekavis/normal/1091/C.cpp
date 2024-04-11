#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 100005;
int cnt1, cnt2, n, a[N], b[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i*i<=n; ++i) if(n%i==0){
		a[++cnt1]=i;
		if(i*i!=n) b[++cnt2]=n/i;
	}
	for(int i=1; i<=cnt2; ++i) printf("%lld ", (ll)n/b[i]*(n/b[i]+1)/2*b[i]-n/b[i]*(b[i]-1));
	for(int i=cnt1; i; --i) printf("%lld ", (ll)n/a[i]*(n/a[i]+1)/2*a[i]-n/a[i]*(a[i]-1));
	return 0;
}