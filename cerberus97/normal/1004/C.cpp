/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int a[N], occ[N];
bool seen[N];

int main() {
	int n; cin >> n;
	int ctr = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		occ[a[i]]++;
		if (occ[a[i]] == 1) {
			++ctr;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		--occ[a[i]];
		if (occ[a[i]] == 0) {
			--ctr;
		}
		if (!seen[a[i]]) {
			seen[a[i]] = true;
			ans += ctr;
		}
	}
	cout << ans;
}