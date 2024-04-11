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

const int N = 1e5 + 10;

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length();
	char min_char = 'z' + 1;
	for (int k = 0; k < n; ++k) {
		if (min_char < s[k]) {
			cout << "Ann\n";
		} else {
			cout << "Mike\n";
		}
		min_char = min(min_char, s[k]);
	}
}