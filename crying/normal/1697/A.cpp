#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=110;
int T,n,m,a[MAXN];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        int sum=0;rep(i,1,n)cin>>a[i],sum+=a[i];
        cout<<max(0,sum-m)<<endl;
    }


    return 0;
}