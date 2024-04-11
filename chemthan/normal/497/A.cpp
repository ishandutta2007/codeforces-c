#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 110;
int n, m;
int a[maxn][maxn];
char s[maxn];
bool flag[maxn][maxn];

void solve() {
	ms(flag, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {scanf("%s", s); FOR(j, 0, m) a[i][j] = s[j];}
	int ans = 0;
	FOR(i, 0, m) {
		bool ck = 0;
		FOR(j, 0, n) {
			if (ck) break;
			FOR(k, j + 1, n) if (!flag[j][k] && a[j][i] > a[k][i]) {ck = 1; break;}
		}
		if (ck) ans++;
		else FOR(j, 0, n) FOR(k, j + 1, n) if (a[j][i] < a[k][i]) flag[j][k] = 1;
	}
	printf("%d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}