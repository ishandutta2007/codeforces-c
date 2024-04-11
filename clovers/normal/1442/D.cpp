/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=3005;
ll dp[N],ans=0;
int n,k,len[N]; vector<ll> v[N],sum[N];

void solve(int l,int r){
    if(l==r){
        for(int i=0;i<=min(k,len[l]);i++) checkmax(ans,dp[k-i]+sum[l][i]);
        return;
    }
    int mid=(l+r)>>1;
    ll tmp[N];
    memcpy(tmp,dp,sizeof(dp));
    for(int i=l;i<=mid;i++){
        for(int j=k;j>=len[i];j--) checkmax(dp[j],dp[j-len[i]]+sum[i][len[i]]);
    }
    solve(mid+1,r);
    memcpy(dp,tmp,sizeof(tmp));
    for(int i=mid+1;i<=r;i++){
        for(int j=k;j>=len[i];j--) checkmax(dp[j],dp[j-len[i]]+sum[i][len[i]]);
    }
    solve(l,mid);
}

int main()
{
    n=read(); k=read();
    for(int i=1;i<=n;i++){
        len[i]=read();
        v[i].resize(len[i]+1); sum[i].resize(len[i]+1);
        for(int j=1;j<=len[i];j++){
            v[i][j]=read();
            sum[i][j]=sum[i][j-1]+v[i][j];
        }
    }
    solve(1,n);
    cout<<ans<<endl;
    return 0;
}