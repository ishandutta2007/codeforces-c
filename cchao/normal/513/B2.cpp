#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef complex<double> cd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rd(a) scanf("%lf", &a)
#define rs(a) scanf("%s", s)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ria(a, n) rep(_, n) ri(a[_])
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define pi(x) printf("%d\n", x)
#define PB push_back
#define SZ(X) ((int)X.size())
#define ALL(X) X.begin(), X.end()
#define fst first
#define snd second
#define Ttimes int T; scanf("%d", &T); while(T--)
#define CASE  int T; scanf("%d", &T); for(int ks = 1; ks <= T; ++ks)

vector<int> ans;
int main() {
	int n;
	long long m;
	cin >> n >> m;

	ans.push_back(n);

	long long t = (1LL << (n - 1)) - m;

	for(int k = n - 1, b = 0; k >= 1; --k, ++b) {
		if(t & (1LL << b)) ans.insert(ans.begin(), k);
		else ans.push_back(k);
	}
	pia(ans, n);

	return 0;
}