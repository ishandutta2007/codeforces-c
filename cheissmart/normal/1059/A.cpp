#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n, l, a;
	cin >> n >> l >> a;
	int lst = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		ans += (t - lst) / a;
		cin >> lst;
		lst += t;
	}
	ans += (l - lst) / a;
	cout << ans << endl;

}