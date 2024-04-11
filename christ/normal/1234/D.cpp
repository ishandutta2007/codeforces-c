#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
char _;
bool neg;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#ifdef getchar_unlocked
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
template <typename t> void scan (t& x) {while((x=getchar())<'0') neg=x=='-'; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); if(neg)x=-x;}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2, MOD = 1e9+7, BASE = 131;
int fpow (int base, int ex) {int res = 1;while (ex) {if (ex&1) res = res*1LL*base%MOD;base = base*1LL*base%MOD;ex>>=1;}return res;}
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand (int a, int b) {return uniform_int_distribution<int>(a,b)(rnd);}
ll randll (ll a, ll b) {return uniform_int_distribution<ll>(a,b)(rnd);}
int moddiv (int a, int b) {return a*1LL*fpow(b,MOD-2)%MOD;}
set<int> st[26];
int arr[MN];
char s[MN];
int main () {
    scanf("%s",s);
    int n = strlen(s);
    for (int i = 1; i <= n; i++) {
        arr[i] = s[i-1]-'a';
        st[arr[i]].insert(i);
    }
    int q;
    scanf("%d",&q);
    while (q--) {
        int type,a,b;
        scanf ("%d %d ",&type,&a);
        if (type == 1) {
            while ((b=getchar())==' ');
            b-='a';
            st[arr[a]].erase(a);
            st[b].insert(a);
            arr[a] = b;
        } else {
            scanf ("%d",&b);
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                auto it = st[i].lower_bound(a);
                if (it != st[i].end() && *it <= b) ++cnt;
            }
            printf ("%d\n",cnt);
        }
    }
    return 0;
}