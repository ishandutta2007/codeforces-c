/*

Code for problem C by savkinsd2089
Generated 15 Dec 2018 at 05.42 pm
The Moon is Waxing Gibbous (51% of Full)










(@)(@)(@)(@)(@)

z_z
=_=
\_()_/

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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

const int mx = 2e5 + 228;
int n;
ll b[mx], a[mx];

signed main() {
	cin >> n;
	n /= 2;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	a[n - 1] = b[n - 1] / 2;
	a[n] = b[n - 1] - b[n - 1] / 2;
	for (int i = n - 2; i >= 0; --i) {
		int j = 2 * n - 1 - i;
		ll sum = b[i];
		ll r_val = sum - a[i + 1];
		ll l_val = sum - a[j - 1];
		if (r_val >= a[j - 1]) {
			a[i] = a[i + 1];
			a[j] = r_val;
		}
		else {
			a[j] = a[j - 1];
			a[i] = l_val;
		}
	}

	for (int i = 0; i < 2 * n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}