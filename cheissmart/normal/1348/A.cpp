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
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int cnt = 0, tot = 0;
		for(int i = n / 2; i < n; i++)
			cnt += 1LL << i;
		for(int i = 1; i <= n; i++)
			tot += 1LL << i;
		int cntt = tot - cnt;
		cout << abs(cnt - cntt) << endl;
	}

}