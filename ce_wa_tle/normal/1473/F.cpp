#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x"in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=2e5+7,mod=1e9+7,iz=1<<21,oz=1<<22,inf=0x3f3f3f3f3f3f3f3f;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1!=o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
bool p1;
aN next,to,head,w,cur,dis,vis,a,b,lst,q;
ll cnt=1;
bool p2;
void add_(ll u,ll v,ll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
void add(ll u,ll v,ll w){
    //printf("%lld %lld %lld\n",u,v,w);
    add_(u,v,w),add_(v,u,0);
}
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
int bfs(ll s,ll e,ll n){
    memcpy(cur,head,(n+1)<<3),memset(dis,0,(n+1)<<3),dis[q[1]=s]=1;
    rfor(ll h=1,t=1,u;h<=t;)rev(i,u=q[h++],v)if(w[i]&&!dis[v])dis[q[++t]=v]=dis[u]+1;
    return dis[e]!=0;
}
ll dfs(ll u,ll t,ll flow){
    if(u==t)return flow;
    ll now=flow;
    vis[u]=1;
    rfor(ll i=cur[u],v,f;v=to[i],i;cur[u]=i=next[i])if(w[i]&&!vis[v]&&dis[v]==dis[u]+1)
    if(!(f=dfs(v,t,std::min(now,w[i])),w[i]-=f,w[i^1]+=f,now-=f))break;
    vis[u]=0;
    return flow-now;
}
int main(){
    //fprintf(stderr,"%.fMiB",(&p2-&p1)/1048576.0);
    IO();
    ll n=readll(),sum=0,s=0,t=n+1;
    rep(i,1,n){
        const ll up=sqrtl(a[i]=readll())+0.05L;
        rep(j,1,up)if(a[i]%j==0&&lst[j])add(i,lst[j],inf);
        rep(j,1,up)if(j*j!=a[i]&&a[i]%j==0&&lst[a[i]/j])add(i,lst[a[i]/j],inf);
        lst[a[i]]=i;
    }
    rep(i,1,n)b[i]=readll(),b[i]>0?sum+=b[i],add(s,i,b[i]):add(i,t,-b[i]);
    //printf("%lld\n",sum);
    while(bfs(s,t,t+1))sum-=dfs(s,t,inf);
    writell(sum);
    return 0;
}