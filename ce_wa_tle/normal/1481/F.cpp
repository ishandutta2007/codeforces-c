#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,n)rfor(ll i=d;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
bool p1;
typedef int ll;
typedef unsigned long long ull;
const ll N=1e5+7,mod=998244353;
typedef ll aN[N];
char is[1<<21],os[1<<22],*i1=is,*i2=is,*o1=os;
int fgc() {
	return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;
}
int fpc(int c) {
	return*o1++=c;
}
void fout() {
	fwrite(os,o1-os,1,stdout),o1=os;
}
int(*gc)()=getchar,(*pc)(int)=putchar;
static inline ll qm(ll&a,ll b) {
	return a>=b?a-=b,1:0;
}
ll readll() {
	ll x=0,w=1;
	int c=gc();
	for(; c<48||c>57; c=gc())c-45||(w=-w);
	for(; c>47&&c<58; c=gc())x=x*10+c-48;
	return x*w;
}
int readchar(int l=33,int r=126) {
	if(l>r)std::swap(l,r);
	int c=gc();
	for(; c<l||c>r; c=gc());
	return c;
}
ll wt[122];
void writell(ll x,int c=10) {
	ll t=0;
	for(ull n=x<0?pc(45),0ull-x:x; n; n/=10)wt[++t]=n%10;
	for(t||pc(48); t;)pc(wt[t--]^48);
	c&&pc(c);
}
int mygets(char*s,int c=0) {
	char*t=s;
	while((*t=gc())>31)t++;
	c&&(*t++=c),*t=0;
	return t-s;
}
int myputs(const char*s,int c=10) {
	const char*t=s;
	while(*t)pc(*t++);
	c&&pc(c);
	return t-s;
}
aN next,to,head,d,cnt,t,f[505],c,ye;
ll md,vnt;
void add(ll u,ll v) {
	next[++vnt]=head[u],to[head[u]=vnt]=v;
}
bool p2;
void dfs(ll u,ll fa) {
	cnt[d[u]=d[fa]+1]++,md=std::max(md,d[u]),ye[d[u]]+=!head[u];
	rev(i,u,v)if(v^fa)dfs(v,u);
}
int main() {
	//IO();
	ll n=readll(),x=readll(),now=0;
	rep(i,2,n)add(readll(),i);
	dfs(1,0);
	rep(i,1,n)t[cnt[i]]++;
	f[0][0]=-1;
	rep(s,1,n)if(ll b=t[s]) {
		c[++now]=s;
		ref(y,0,s)rfor(ll i=y,j=0,lst=-mod; i<=n; i+=s,j++) {
			if(f[now-1][i])lst=j;
			if(j-lst<=b)f[now][i]=~(j-lst);
		}
	}
	if(f[now][x]) {
		writell(md);
		for(ll i=now,j=x; i; j-=c[i]*~f[i][j],i--)t[c[i]]=~f[i][j];
		rep(i,1,n)if(t[cnt[i]])t[cnt[i]]--,cnt[i]=-1;
		rep(i,1,n)pc(97+!!~cnt[d[i]]);
	} else {
		ll a=x,b=n-x,js=0,yub=0;
		writell(md+1);
		rep(i,1,md)cnt[i]=a>b?(a-=cnt[i])<0&&(js=i,yub=-a,b+=a,a=0),0:((b-=cnt[i])<0&&(yub=ye[js=i]+b,a+=b,b=0),1);
//		printf("%d %d %d %d\n",a,b,js,yub);
		rep(i,1,n)pc(d[i]==js&&!head[i]?97+(yub-->0):97+cnt[d[i]]);
	}
	return 0;
}
/*
11 9
1 1 1 1 1 1 1 4 5 6
*/