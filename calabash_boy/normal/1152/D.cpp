/* Generated by powerful Codeforces Tool
 * Author: calabash_boy_love_15 
 * Time: 2019-04-26 23:34:51
 * Personal Code Template: https://github.com/4thcalabash/ACM-Code-Library
**/
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif
#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)
#define range(x) x.begin(),x.end()
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
/************* header ******************/

const int maxn = 1000+5;
const int mod = 1e9 + 7;
inline void add(int &tar,int val){
    (tar += val) %= mod;
}
int n;
int dp[maxn][maxn];
int main(){
    cin>>n;
    n++;
    for (int i=n;i>=1;i--){
        for (int j=n;j>=1;j--){
            if (i == n && j == n)continue;
            //right
            int jj = j+1;
            int ii = i;
            if (ii >= jj && ii <=n){
                add(dp[i][j],dp[ii][jj]);
            }
            //down
            ii = i+1;
            jj = j;
            if (ii >= jj && ii <=n){
                add(dp[i][j],dp[ii][jj]);
            }
            int f = n + n - i - j;
            if (f % 2 == 1){
                add(dp[i][j],1);
            }
        }
    }
    cout<<dp[1][1]<<endl;
    return 0;
}