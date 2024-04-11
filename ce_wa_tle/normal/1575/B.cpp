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
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout);
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
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
typedef long double ld;
const ld pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986L;
ll n,k;
ld a[N],d[N],dis[N],rho[N];
int check(ld m){
    m*=2;
    ld x;
    ll t=0;
    rep(i,1,n){
        if(dis[i]>m)continue;
        x=acosl(dis[i]/m),t+=2,a[t]=2*pi+(a[t-1]=rho[i]-x),d[t]=2*pi+(d[t-1]=rho[i]+x);
    }
    std::sort(a+1,a+t+1),
    std::sort(d+1,d+t+1);
    //rep(i,1,t)printf("%Lf ",a[i]);puts("");
    //rep(i,1,t)printf("%Lf ",d[i]);puts("");
    ll r=0,p=0;
    if(r>=k)return 1;
    rep(i,1,t){
        while(p<t&&a[p+1]<d[i])r++,p++;
        if(r>=k)return 1;
        r--;
    }
    return 0;
}
int main(){
    IO();
    n=readll(),k=readll();
    rep(i,1,n){
        ll x=readll(),y=readll();
        if(x*x+y*y==0)dis[i]=mod,k--;
        else dis[i]=sqrtl(x*x+y*y),rho[i]=atan2(y,x);
        //printf("%Lf %Lf\n",dis[i]*dis[i],rho[i]);
    }
    ll sr=1;
    if(check(1))sr=0;
    else per(i,4,0)if(!check(sr<<(1<<i)))sr<<=1<<i;
    ld l=sr,r=sr*2+!sr;
    rep(j,1,14){
        ld m=(l+r)/2;
        if(check(m))r=m;
        else l=m;
    }
    printf("%Lf\n",r);
    return 0;
}