#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

pi a[1005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i].F;
		a[i].S = i+1;
	}
	sort(a, a+n);
	reverse(a, a+n);
	int ans = 0, x = 0;
	for(int i=0;i<n;i++) {
		ans += a[i].F * x  + 1;
		x++;
	}
	cout << ans << endl;
	for(int i=0;i<n;i++)
		cout << a[i].S << " ";
		
}