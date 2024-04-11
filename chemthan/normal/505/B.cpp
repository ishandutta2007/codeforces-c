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
vii adj[maxn];
bool vis[maxn];
bool st;

void dfs(int u, int t, int c) {
     vis[u] = 1;
     if (u == t) {st = true; return;}
     FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].first;
            if (!vis[v] && adj[u][i].second == c) dfs(v, t, c);
     }
}

void solve() {
     scanf("%d%d", &n, &m);
     FOR(i, 0, m) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
     }
     int q; scanf("%d", &q);
     while (q--) {
           int u, v; scanf("%d%d", &u, &v); u--; v--;
           int ans = 0;
           FOR(i, 1, m + 1) {
                  ms(vis, 0); st = false;
                  dfs(u, v, i);
                  if (st) ans++;
           }
           printf("%d\n", ans);
     }
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