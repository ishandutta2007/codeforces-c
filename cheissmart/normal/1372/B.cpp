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
		int n;
		cin >> n;
		ll ans = 1e18, x, y;
		for(int i = 1; i * i <= n; i++) {
			if(n % i == 0) {
				for(int j:{i, n/i}) {
					if(j != n) {
						ll cur = (ll) j * (n - j) / __gcd(j, n - j);
						if(cur < ans) {
							ans = cur;
							x = j, y = n - j;
						}
					}
				}
			}
		}
		cout << x << " " << y << endl;;
	}
	
}