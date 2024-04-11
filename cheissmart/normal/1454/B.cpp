#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

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
		int n;
		cin >> n;
		vi cnt(n + 1), pos(n + 1);
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
			pos[x] = i + 1;
		}
		int ans = -1;
		for(int i = 1; i <= n; i++) if(cnt[i] == 1) {
			ans = pos[i];
			break;
		}
		cout << ans << endl;
	}

}