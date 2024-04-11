#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=3e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
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
int myputs(const char*s=0,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
ll inv(ll a,ll b=mod){
    ll x=1,y=0,m=b;
    while(b){
        ll t=a/b;
        std::swap(x,y),
        std::swap(a,b),
        y-=t*x,
        b-=t*a;
    }
    return(x+m)%m;
}
aN jc,njc,f;
ll C(ll n,ll m){
    return n<0||n>m?0:jc[m]*njc[n]%mod*njc[m-n]%mod;
}
int main(){
    IO();
    ll n=readll(),q=readll();
    const ll m=3*(n+1);
    rep(i,jc[0]=1,m)jc[i]=jc[i-1]*i%mod;
    njc[m]=inv(jc[m]);
    per(i,m,1)njc[i-1]=njc[i]*i%mod;
    rep(i,0,m)f[i]=C(i+1,m);
    per(i,m,2)f[i-1]=(f[i-1]+(mod-3)*f[i])%mod,f[i-2]=(f[i-2]+(mod-3)*f[i])%mod;
    //rep(i,0,m)writell(f[i]);
    rep(i,1,q)writell(f[readll()+2],10);
    return 0;
}