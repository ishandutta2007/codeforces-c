#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int d, k;

double getdis(int x, int y) {
	return sqrt(1ll * x * x + 1ll * y * y) - 1e-10;
}

void solve() {
	scanf("%d%d", &d, &k);
	int dist = d / sqrt(2) / k + 1e-10;
	if (getdis(k * dist, k * (dist + 1)) <= d) puts("Ashish");
	else puts("Utkarsh");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}