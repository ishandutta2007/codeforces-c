#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
void writell(cll u,int c=32){
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
#define $1(x...)x
#define $2(x...)x
cll IO_res=IO(),T=readll();
void init(){
}
aN a,s;
ll lst[33],f[33];
void calc(){
    cll n=readll();
    ll cnt=0,mx=0,s=0,z=0,df=0,sd=0;
    memset(lst,0,sizeof lst),memset(f,0,sizeof f);
    rep(i,1,n){
        cll x=a[i]=readll()?:(++cnt,1),l=__builtin_ctz(x);
        mx=std::max(mx,l);
        if(!lst[l])lst[l]=i;
        if(x&~f[l]){
            if(!f[l])f[l]=x;
            ll s=x;
            rep(i,0,30)if(x>>i&1)s|=f[i];
            rep(i,0,30)if(s>>i&1)f[i]|=s;
        }
        z|=x;
    }
    cll lim=(1<<mx)-1;
    rep(i,1,n)if(a[i]&lim)s|=a[i];else df=i;
    if((z&~f[mx])==0){
        writell(cnt,10);
        rep(i,1,n)writell(a[i],i==n?10:32);
        return;
    }
    cll c=__builtin_ctz(z^f[0]);
    if((f[c]|f[0])==z){
        a[lst[c]]++,cnt++;
        writell(cnt,10);
        rep(i,1,n)writell(a[i],i==n?10:32);
        return;
    }
    if(df==lst[mx])sd=df;
    ll st[33],t=0;
    rep(i,1,n)if(!(a[i]&lim)){
        if(s&a[i]){
            sd=i==df?lst[mx]:df;
            rep(j,1,t)if((a[i]&a[st[j]])!=lim+1)sd=st[j];
            break;
        }else if(a[i]!=lim+1){
            st[++t]=i;
            s|=a[i]^(lim+1);
        }
    }
    if(sd){
        a[sd]--,cnt++;
        writell(cnt,10);
        rep(i,1,n)writell(a[i],i==n?10:32);
        return;
    }
    a[df]++,a[lst[mx]]--,cnt+=2;
    writell(cnt,10);
    rep(i,1,n)writell(a[i],i==n?10:32);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}