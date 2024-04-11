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
	string c; cin >> c;
	for (int i = 0; i < 5; ++i) {
		string s; cin >> s;
		if (s[0] == c[0] or s[1] == c[1]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}