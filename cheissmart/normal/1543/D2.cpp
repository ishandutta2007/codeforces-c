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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int tt = 0, sign = 1;
		auto sub = [&] (int x, int y) {
			int pw = 1, ans = 0;
			while(x || y) {
				int dx = x % k, dy = y % k;
				x /= k, y /= k;
				ans += (dx - dy + k) % k * pw;
				pw *= k;
			}
			return ans;
		};

		auto add = [&] (int x, int y) {
			int pw = 1, ans = 0;
			while(x || y) {
				int dx = x % k, dy = y % k;
				x /= k, y /= k;
				ans += (dx + dy) % k * pw;
				pw *= k;
			}
			return ans;
		};

		auto trans = [&] (int i, int tt, int sign) {
			if(sign == 1) return add(tt, i);
			else return sub(tt, i);
		};

		for(int i = 0; i < n; i++) {
			cout << trans(i, tt, sign) << endl;
			int res;
			cin >> res;
			if(res == 1) break;
			else {
				tt = sub(trans(i, tt, sign), tt);
				sign *= -1;
			}
		}
	}
	
}