/*

Code for problem B by cookiedoth
Generated 03 Mar 2020 at 05.40 PM



10%

30%

50%

70%

100%

-_-
z_z
>_<

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
string s;
vector<int> op, cl;

signed main() {
	fast_io();
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			op.push_back(i);
		} else {
			cl.push_back(i);
		}
	}
	reverse(all(cl));
	int cnt = 0;
	while (cnt < op.size() && cnt < cl.size() && op[cnt] < cl[cnt]) {
		cnt++;
	}
	vector<int> ans;
	for (int i = 0; i < cnt; ++i) {
		ans.push_back(op[i]);
	}
	for (int i = cnt - 1; i >= 0; --i) {
		ans.push_back(cl[i]);
	}
	if (ans.empty()) {
		cout << 0 << "\n";
		exit(0);
	}
	cout << 1 << "\n";
	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}