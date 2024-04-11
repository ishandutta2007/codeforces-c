/*

Code for problem D by cookiedoth
Generated 31 Mar 2020 at 06.31 PM


 ] 
 
Il] 


>_<
\_()_/
^_^

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

const int mx = 510;
int n = 2, m = 3;
int a[mx][mx];

signed main() {
	fast_io();
	int k;
	cin >> k;
	int val = 1;
	while (val <= k) {
		val <<= 1;
	}
	a[0][0] = val + k;
	a[0][1] = val;
	a[1][0] = k;
	a[1][1] = val + k;
	a[1][2] = k;
	cout << n << " " << m << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}