#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> a(n); ll sum = 0;
    for (int i = 0; i < n; i++) scanf ("%d",&a[i]), sum += a[i];
    int m;
    scanf ("%d",&m);
    vector<int> b(m); ll s2 = 0;
    for (int i = 0; i < m; i++) scanf ("%d",&b[i]), s2 += b[i];
    if (sum != s2) return !printf ("-1\n");
    ll cura = 0, curb = 0; int bp = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        cura += a[i];
        while (curb < cura) curb += b[bp++];
        if (curb == cura) cura = curb = 0, ret++;
    }
    printf ("%d\n",ret);
    return 0;
}