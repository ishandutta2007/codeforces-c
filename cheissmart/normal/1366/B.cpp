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
	
	int t;
	cin >> t;
	while(t--) {
		int n, x, m;
		cin >> n >> x >> m;
		int lb = x, rb = x;
		for(int i = 0; i < m; i++) {
			int l, r;
			cin >> l >> r;
			if(l > rb || r < lb) continue;
			lb = min(l, lb);
			rb = max(r, rb);
		}
		cout << rb - lb + 1 << endl;
	}	
	
}