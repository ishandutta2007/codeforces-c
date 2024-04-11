/*

Code for problem A by cookiedoth
Generated 16 Feb 2019 at 07.32 P


  !











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

const int mx = 3e5 + 228;
int n, a[mx], pref[mx];
ll ans = 0;
map<int, ll> cnt;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] ^ a[i - 1];
	}
	for (int i = 0; i <= n; i += 2) {
		cnt[pref[i]]++;
	}
	for (auto pp : cnt) {
		ans += (pp.second) * (pp.second - 1) / 2;
	}
	cnt.clear();
	for (int i = 1; i <= n; i += 2) {
		cnt[pref[i]]++;
	}
	for (auto pp : cnt) {
		ans += (pp.second) * (pp.second - 1) / 2;
	}
	cout << ans << endl;
}