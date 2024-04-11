#include <bits/stdc++.h>
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

const int INF = 1e9 + 7, N = 4e6 + 7;

int dp[N], ps[N];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;

	auto add = [&] (int& a, int b) {
		a += b;
		if(a >= m)
			a -= m;
	};
	int p = 0;
	for(int i = 1; i <= n; i++) {
		if(i == 1) dp[i] = 1;
		add(ps[i], ps[i - 1]);
		add(dp[i], p);
		add(dp[i], ps[i]);
		for(int r = 1; 1LL * r * i <= n; r++) {
			int lb = max(r * i, i + 1), rb = r * i + r;
			add(ps[lb], dp[i]);
			if(rb < N)
				add(ps[rb], m - dp[i]);
		}
		add(p, dp[i]);
	}
	cout << dp[n] << '\n';

}