#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1222222;
int n,a[N],f[N],pos[N];
int main() {
	read(n);rep(i,1,n)read(a[i]),pos[a[i]]=i;int res=0;
	per(i,n,1){
		f[i]=1;for(register int j=a[i]+a[i];j<=1000000;j+=a[i])f[i]=max(f[i],f[pos[j]]+1);
		res=max(res,f[i]);
	}
	printf("%d",res);
	return 0;
}