/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

int a[N], occ[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			occ[a[i]] = -1;
		}
		int ans = n + 1;
		for (int i = 1; i <= n; ++i) {
			if (occ[a[i]] != -1) {
				ans = min(ans, i - occ[a[i]] + 1);
			}
			occ[a[i]] = i;
		}
		if (ans == n + 1) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}
}