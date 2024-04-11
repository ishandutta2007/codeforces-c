/*

Code for problem A by cookiedoth
Generated 11 Apr 2021 at 05.32 PM



10%

30%

50%

70%

100%

o_O
-_-
~_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void solve() {
	int n, k;
	cin >> n >> k;
	if (n > 1) {
		int cnt = (n - 1) / 2;
		if (cnt < k) {
			cout << -1 << '\n';
			return;
		}
	}
	if (n == 1 && k == 1) {
		cout << -1 << '\n';
		return;
	}
	vector<int> ans(n, -1);
	int ptr = n - 1;
	int ps = 1;
	for (int i = 0; i < k; ++i) {
		ans[ps] = ptr--;
		ps += 2;
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			ans[i] = ptr--;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}