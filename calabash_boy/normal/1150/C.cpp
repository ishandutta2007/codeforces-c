/* Generated by powerful Codeforces Tool
 * Author: calabash_boy_love_15 
 * Time: 2019-05-03 15:51:46
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
int cnt[3];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int ai;
        cin>>ai;
        cnt[ai] ++;
    }
    if (cnt[1] == 0){
        for (int i=1;i<=n;i++){
            printf("2 ");
        }
        puts("");
        return 0;
    }
    if (cnt[2] == 0){
        for (int i=1;i<=n;i++){
            printf("1 ");
        }
        puts("");
        return 0;
    }
    printf("2 1 ");
    cnt[1] --;
    cnt[2] --;
    for (int i=1;i<=cnt[2];i++){
        printf("2 ");
    }
    for (int i=1;i<=cnt[1];i++){
        printf("1 ");
    }
    puts("");
    return 0;
}