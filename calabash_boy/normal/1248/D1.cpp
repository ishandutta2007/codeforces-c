/* Generated by powerful Codeforces Tool
 * Author: calabash_boy_love_15 
 * Time: 2019-11-02 18:32:51
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
const int maxn = 505;
char s[maxn];
int n;
pair<int,pair<int,int>> ans = {0,{1,1}};
int sum[maxn];
int min_l[maxn];
int min_r[maxn];
int gao(){
    min_l[0] = 0;
    for (int i=1;i<=n;i++){
        sum[i] = sum[i-1] + (s[i] == '('?1:-1);
        min_l[i] = min(min_l[i-1], sum[i]);
    }
    min_r[n+1] = 0;
    for (int i=n;i>=1;i--){
        min_r[i] = min(min_r[i+1],sum[i]);
    }
    int cnt = 0;
    for (int i=1;i<=n;i++){
        if (min_r[i] - sum[i-1] >= 0 and sum[n] - sum[i-1] + min_l[i-1] >= 0 and sum[n] == 0)cnt ++;
    }
    return cnt;
}
int main(){
    cin>>n;
    cin>>s+1;
    for (int i=1;i<n;i++)for (int j=i+1;j<=n;j++){
        swap(s[i],s[j]);
        ans = max(ans,make_pair(gao(),make_pair(i,j)));
        swap(s[i],s[j]);
    }
    cout<<ans.first<<endl;
    cout<<ans.second.first <<" "<<ans.second.second<<endl;
    return 0;
}