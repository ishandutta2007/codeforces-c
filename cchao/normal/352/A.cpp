#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)


int main() {
    int cnt[10] = {};
    int n; ri(n); rep(i, n) {
        int t; ri(t); cnt[t]++;
    }
    while(cnt[5] % 9) cnt[5]--;
    if(cnt[0]) {
        if(cnt[5] == 0) cnt[0] = 1;
        while(cnt[5]--) putchar('5');
        while(cnt[0]--) putchar('0');
        puts("");
    }
    else puts("-1");
    return 0;
}