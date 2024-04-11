#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

bool arr[228];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2; ++i)
	{
		int p;
		scanf("%d", &p);
		for (int j = 0; j < p; ++j)
		{
			int x;
			scanf("%d", &x);
			arr[x] = true;
		}
	}

	bool f = true;
	for (int i = 1; i <= n; ++i)
		f &= arr[i];
	if (f)
		cout << "I become the guy.";
	else
		cout << "Oh, my keyboard!";

	return 0;
}