#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
ll n;vector<ll>c[77];
int main() {
	read(n);
	rep(i,1,n){
		ll x;read(x);ll y=0;
		while(x%2==0)x/=2,y++;
		c[y].pb(x<<y);
	}
	int mx=0;rep(i,0,60)if(SZ(c[i])>SZ(c[mx]))mx=i;
	printf("%d\n",n-SZ(c[mx]));
	rep(i,0,60)if(i!=mx)rep(j,0,SZ(c[i])-1)printf("%lld ",c[i][j]);
	return 0;
}