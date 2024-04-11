#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

struct DominatorTree {
	static const int maxn = 200000 + 10;
	int n, rt;
	vector<int> adj1[maxn];
	vector<int> adj2[maxn];
	vector<int> tree[maxn];
	vector<int> bucket[maxn];
	int par[maxn];
	int sdm[maxn];
	int dom[maxn];
	int dsu[maxn];
	int lbl[maxn];
	int arr[maxn];
	int rev[maxn];
	int tms;
	
	void init(int n, int rt) {
		this->n = n;
		this->rt = rt;
		for (int i = 0; i < n; i++) {
			adj1[i].clear();
			adj2[i].clear();
			tree[i].clear();
			bucket[i].clear();
		}
		fill_n(arr, n, -1);
		tms = 0;
	}
	void add(int u, int v) {
		adj1[u].push_back(v);
	}
	void dfs(int u) {
		arr[u] = tms, rev[tms] = u;
		lbl[tms] = tms, sdm[tms] = tms, dsu[tms] = tms;
		tms++;
		for (int i = 0; i < (int) adj1[u].size(); i++) {
			int w = adj1[u][i];
			if (!~arr[w]) dfs(w), par[arr[w]] = arr[u];
			adj2[arr[w]].push_back(arr[u]);
		}
	}
	int find(int u, int x = 0) {
		if (u == dsu[u]) return x ? -1 : u;
		int v = find(dsu[u], x + 1);
		if (v < 0) return u;
		if (sdm[lbl[dsu[u]]] < sdm[lbl[u]]) {
			lbl[u] = lbl[dsu[u]];
		}
		dsu[u] = v;
		return x ? v : lbl[u];
	}
	void join(int u, int v) {
		dsu[v] = u;
	}
	void build() {
		dfs(rt);
		for (int i = tms - 1; i >= 0; i--) {
			for (int j = 0; j < (int) adj2[i].size(); j++) {
				sdm[i] = min(sdm[i], sdm[find(adj2[i][j])]);
			}
			if (i > 1) bucket[sdm[i]].push_back(i);
			for (int j = 0; j < (int) bucket[i].size(); j++) {
				int w = bucket[i][j], v = find(w);
				if (sdm[v] == sdm[w]) dom[w] = sdm[w];
				else dom[w] = v;
			}
			if (i > 0) join(par[i], i);
		}
		for (int i = 1; i < tms; i++) {
			if (dom[i] != sdm[i]) dom[i] = dom[dom[i]];
			tree[rev[i]].push_back(rev[dom[i]]);
			tree[rev[dom[i]]].push_back(rev[i]);
		}
	}
} domtree;

const int maxn = 200000 + 10;
int n, m, s;
vii adj[maxn];
long long d[maxn];
int size[maxn];

void dfs(int u, int p = -1) {
	size[u] = 1;
	FOR(i, 0, sz(domtree.tree[u])) {
		int v = domtree.tree[u][i];
		if (v != p) {
			dfs(v, u);
			size[u] += size[v];
		}
	}
}

void solve() {
    cin >> n >> m >> s; s--;
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    priority_queue<pair<long long, int> > pq;
    fill_n(d, n, LINF);
    d[s] = 0;
    pq.push(mp(-d[s], s));
    while (sz(pq)) {
        long long t = -pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (d[u] != t) continue;
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].fi;
            int w = adj[u][i].se;
            if (chkmin(d[v], d[u] + w)) {
                pq.push(mp(-d[v], v));
            }
        }
    }
    domtree.init(n, s);
    FOR(u, 0, n) {
    	FOR(i, 0, sz(adj[u])) {
    		int v = adj[u][i].fi;
    		int w = adj[u][i].se;
    		if (d[v] == d[u] + w) {
    			domtree.add(u, v);
    		}
    	}
    }
    domtree.build();
    dfs(s);
    int ans = 0;
    FOR(i, 0, n) if (i - s) {
    	chkmax(ans, size[i]);
    }
    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}