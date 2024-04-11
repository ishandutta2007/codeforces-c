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

const int N = 1e3 + 10;

int a[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; ++i)
		cin >> a[i];

	sort(a, a + 2 * n);
	if (a[n - 1] == a[n])
		cout << "NO";
	else
		cout << "YES";
}