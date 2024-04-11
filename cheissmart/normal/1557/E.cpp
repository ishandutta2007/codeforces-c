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

#define ask() { cout << x << ' ' << y << endl; cin >> res; if(res == "Done") return; }

void solve() {
	int x = 1, y = 8;
	string res;
	while(true) {
		assert(x < 8);
		if(y != 1) ask();
		y = 1;
		while(true) {
			ask();
			if(int(res.size()) >= 2 && res.substr(0, 2) == "Up" && y != 1) {
				y = 1;
				continue;
			}
			if(int(res.size()) >= 4 && res.substr(0, 4) == "Down") {
				x++;
				continue;
			}
			if(y == 8) {
				x++;
				break;
			}
			y++;
		}
	}
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}