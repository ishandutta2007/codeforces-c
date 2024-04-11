#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}
const LL LIM = 1e7;
inline LL fastpo(LL x, LL n, LL mod) {
	LL res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
inline LL limpo(LL x, LL n) {
	LL res(1);
	while(n) {
		if(n & 1) {
			res = min(LIM, res * (LL)x);
		}
		x = min(LIM, x * (LL) x);
		n /= 2;
	}
	return res;
}

inline string itoa(int x, int width = 0) {
  string res;
  if(x == 0) res.push_back('0');
  while(x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}
const int N = 1000033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N];
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		int n, p;
		scanf("%d%d", &n, &p);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + 1 + n);
		int ac = 0, ap, ans;
		for(int i = n; i >= 1; i--) {
			if(ac == 0) {
				ac = 1;
				ap = a[i];
				ans = fastpo(p, a[i], mod);
			}else {
				LL nwac = ac * limpo(p, ap - a[i]);
				if(nwac >= LIM) {
					ac = LIM;
				}else {
					ac = nwac;
				}
				ap = a[i];
				ac -= 1;
				ans = (ans - fastpo(p, a[i], mod) + mod) % mod;
			}
		}
		printf("%d\n", ans);
	}
}