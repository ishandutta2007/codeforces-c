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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, mod = 998244353;

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	for (auto& i : p) {
		cin >> i;
	}
	ll sum = 0, ways = 1;
	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		if (p[i] >= n - k + 1) {
			sum += p[i];
			pos.pb(i);
		}
	}
	int sz = pos.size();
	for (int i = 0; i < sz - 1; ++i) {
		ways = (ways * (pos[i + 1] - pos[i])) % mod;
	}
	cout << sum << ' ' << ways << endl;
}