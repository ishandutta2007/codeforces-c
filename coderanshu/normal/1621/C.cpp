#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    auto get = [&](int i) {
        cout << "? " << i << "\n" << flush;
        int x;
        cin >> x;
        return x;
    };
    vector<bool> vis(n+1);
    vector<int> ans(n+1);
    int d = 0;
    for(int i=1;i<=n;++i) {
        if(vis[i]) {
            continue;
        }
        vector<int> v;
        int cur = i;
        while(true) {
            cur = get(i);
            if(v.empty()) {
                v.push_back(cur);
            }
            else if(v[0] == cur) {
                break;
            }
            else {
                v.push_back(cur);
            }
        }
        for(int j=0;j<sz(v);++j) {
            vis[v[j]] = 1;
            ans[v[j]] = v[(j + 1) % sz(v)];
        }
    }
    cout << "! ";
    for(int i=1;i<=n;++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    cout << flush;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}