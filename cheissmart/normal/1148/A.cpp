#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	ll a, b, c;
	cin >> a >> b >>c;
	ll ans = c * 2;
	ll d = min(a, b);
	a -= d;
	b -= d;
	ans += 2 * d;
	if(a) ans++, a--;
	if(b) ans++, b--;
	cout << ans << endl;
	
}