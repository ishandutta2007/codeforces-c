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
		int n, l, r;
		cin >> n >> l >> r;
		vi cnta(n), cntb(n);
		for(int i = 0; i < l; i++) {
			int x;
			cin >> x;
			cnta[--x]++;
		}
		for(int i = 0; i < r; i++) {
			int x;
			cin >> x;
			cntb[--x]++;
		}
		if(l < r) swap(l, r), swap(cnta, cntb);
		int move = (l - r) / 2, match = 0, ans = move;
		for(int i = 0; i < n; i++) {
			int tt = min(cnta[i], cntb[i]);
			cnta[i] -= tt, cntb[i] -= tt;
			match += tt;
			tt = min(move, cnta[i] / 2);
			move -= tt;
			match += tt;
		}
		ans += n / 2 - match;
		cout << ans << '\n';
	}

}