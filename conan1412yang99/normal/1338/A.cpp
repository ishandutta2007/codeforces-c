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

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		int mx = 0;
		for(int i=0;i<n-1;i++) {
			if(a[i] > a[i+1]) {
				mx = max(mx, a[i] - a[i+1]);
				a[i+1] = a[i];
			}
		}
		if(mx == 0) cout << 0 << endl;
		else {
			cout << __lg(mx) + 1 << endl;
		}
	}

}