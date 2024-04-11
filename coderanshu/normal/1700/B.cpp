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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    string s, ans(n, '0');
    cin >> s;
    if(s[0] != '9') {
        for(int i=0;i<n;++i) {
            ans[i] = '9' - s[i] + '0';
        }
    }
    else {
        string t(n + 1, '1');
        for(int i=n-1;i>=0;--i) {
            int up = t[i + 1] - '0';
            int down = s[i] - '0';
            if(up >= down) {
                ans[i] = up - down + '0';
            }
            else {
                ans[i] = 10 + up - down + '0';
                --t[i];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
    
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}