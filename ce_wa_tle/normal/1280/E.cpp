#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout);
typedef long long ll;
typedef unsigned long long ull;
const ll N=1.1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN st,n,c,ans;
ll tn,tc,ts,id;
char s[N];
void calc(){
    ll&b=n[tn--],&a=n[tn];
    switch(c[tc--]){
        case'P':a+=b;break;
        case'S':if(a<=b)ts-=b;
        else memcpy(st+ts-b-a+1,st+ts-b+1,b<<3),ts-=a,a=b;
    }
}
int mygets_k(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<32);
    while((*t=gc())>31)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
void calc(int cases){
    const ll r=readll();
    mygets_k(s);
    tn=tc=ts=id=0;
    rfor(const char*t=s;*t;)switch(const char ch=*t++){
        case' ':break;
        case'*':n[++tn]=1,st[++ts]=++id;break;
        case'(':c[++tc]='(';break;
        default:while(c[tc]!='(')calc();
        if(ch==')')tc--;else c[++tc]=ch;
    }
    rep(i,1,ts)ans[st[i]]=cases;
    myputs("REVOLTING",32);
    const ll val=r*ts;
    rep(i,1,id)writell(val&-(ans[i]==cases),i==id?10:32);
}
int main(){
    IO();
    ll T=readll(),cnt=0;
    while(T--)calc(++cnt);
    return 0;
}
/*
2
3 ( ( * P * ) S * )
3 ( ( ( * P * ) S ( * P * ) ) S * )
*/