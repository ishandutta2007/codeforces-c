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
const ll N=4e5+7,mod=1e9+7,iz=1<<21,oz=1<<22,inf=0x3f3f3f3f3f3f3f3f;
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
ll a[1111][1111],b[1111][1111];
char s[N];
void calc(){
    ll n=readll();readll();
    rep(i,1,n)rep(j,1,n)a[i][j]=readll();
    mygets(s);
    ll p[3]={0,1,2},d[3]={0,0,0};
    char*t=s;
    while(ll c=*t++)switch(c){
        case'L':d[1]--;break;
        case'R':d[1]++;break;
        case'U':d[0]--;break;
        case'D':d[0]++;break;
        case'I':std::swap(p[1],p[2]),std::swap(d[1],d[2]);break;
        case'C':std::swap(p[0],p[2]),std::swap(d[0],d[2]);break;
    }
    rep(i,1,n)rep(j,1,n){
        #define md(x)(((x)%n+n-1)%n+1)
        const ll tr[]={i,j,a[i][j]};
        b[md(tr[p[0]]+d[0])][md(tr[p[1]]+d[1])]=md(tr[p[2]]+d[2]);
    }
    rep(i,1,n)rep(j,1,n)writell(b[i][j],j==n?10:32);
    pc(10);
}
int main(){
    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}