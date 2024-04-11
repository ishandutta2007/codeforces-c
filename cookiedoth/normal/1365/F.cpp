/*

Code for problem F by cookiedoth
Generated 07 Jun 2020 at 06.55 PM



10%

30%

50%

70%

100%

^_^
~_^
=_=

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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

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

int n;

vector<pair<int, int> > read() {
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<pair<int, int> > res;
	for (int i = 0; i < n / 2; ++i) {
		if (a[i] > a[n - 1 - i]) {
			swap(a[i], a[n - 1 - i]);
		}
		res.emplace_back(a[i], a[n - 1 - i]);
	}
	if (n % 2 == 1) {
		res.emplace_back(a[n / 2], -1);
	}
	sort(all(res));
	return res;
}

void solve() {
	cin >> n;
	vector<pair<int, int> > a = read();
	vector<pair<int, int> > b = read();
	if (a == b) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}