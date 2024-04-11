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
	
	int n, m;
	cin >> n >> m;
	vi v, vv;
	map<int, int> d;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		d[t] = 0;
		v.PB(t);
	}
	int ans = 0;
	for(int i=0;i<v.size();i++) {
		if(vv.size() >= m) break;
		int u = v[i];
		if(d[u] != 0) {
			ans += d[u];
			vv.PB(u);
		}
		if(!d.count(u-1)) {
			d[u-1] = d[u] + 1;
			v.PB(u-1);
		}

		if(!d.count(u+1)) {
			d[u+1] = d[u] + 1;
			v.PB(u+1);
		}
	}
	cout << ans << endl;
	for(int i=0;i<m;i++) cout <<vv[i] << " ";

}