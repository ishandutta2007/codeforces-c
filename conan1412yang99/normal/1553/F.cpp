#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 3e5 + 7;

int bit[N]; 

void add(int i, int val = 1) {
	for(; i < N; i += i & -i)
        bit[i] += val;
}

int qry(int i) {
	i = min(i, N - 1);
	int res = 0;
    for(; i; i -= i & -i)
        res += bit[i];
    return res;
}

ll bit1[N]; 

void adds(int i, ll val) {
	for(; i < N; i += i & -i)
        bit1[i] += val;
}

ll qrys(int i) {
	i = min(i, N - 1);
	ll res = 0;
    for(; i; i -= i & -i)
        res += bit1[i];
    return res;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	ll ans = 0, sum = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans += sum;
		ans += ll(x) * i;
		for(int mul = 1; mul * x < N; mul++) {
			int l = x * mul, r = x * (mul + 1) - 1;
			ans -= ll(qry(r) - qry(l - 1)) * mul * x;
		}
		ll tt = 0;
		for(int l = 1; l < x;) {
			int r = x / (x / l);
			ll ttt = qrys(r);
			ans -= (ttt - tt) * (x / l);
			tt = ttt;
			l = r + 1;
		}
		add(x, 1);
		adds(x, x);
		sum += x;
		cout << ans << ' ';
	}

}