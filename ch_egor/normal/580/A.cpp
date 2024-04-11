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
	
	int ans = 0;
	int len = 0;
	int last = -228;
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		if (x >= last)
		{
			last = x;
			++len;
		}
		else
		{
			len = 1;
			last = x;
		}
		ans = max(ans, len);
	}
	cout << ans;
	return 0;
}