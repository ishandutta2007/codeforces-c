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
ll qz[44];multiset<int>Set[44];int mx=30,cnt;
inline int query(){
	ll now=0;int res=0;
	rep(i,0,mx)if(SZ(Set[i])){
		res+=*Set[i].begin()>2*now;now=qz[i];
	}
	return res;
}
int main() {
	int q;read(q);
	while(q--){
		char t[3];scanf("%s",t);int x;read(x);
		int y=0;while(x>>y+1)y++;
		if(t[0]=='+'){
			Set[y].insert(x);rep(i,y,mx)qz[i]+=x;cnt++;
		}
		else{
			Set[y].erase(Set[y].find(x));rep(i,y,mx)qz[i]-=x;cnt--;
		}
		printf("%d\n",cnt-query());
	}
	return 0;
}