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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n, k;
		cin >> n >> k;
		int r = INF, l = -INF;
		for(int i=0;i<n;i++) {
			int x;
			cin >> x;
			r = min(r, x + k);
			l = max(l, max(0, x - k));
		}
		if(r >= l) cout << r << endl;
		else cout << -1 << endl;
	}

}