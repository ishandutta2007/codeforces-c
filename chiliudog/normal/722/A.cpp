#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
#define dg(...) fprintf(stderr,__VA_ARGS__);
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
int x,y,z;
inline int dif(int x,int y){
	int res=0;
	if(x%10!=y%10)res++;
	if(x/10!=y/10)res++;
	return res;
}
int main(){
	read(x);read(y);read(z);int res=0;
	if(z>=60){
		z=z%10;
	}int ans;
	if(x==12){
		int bf=y;ans=1;
		rep(i,1,12)if(dif(i,bf)<dif(ans,bf))ans=i;
	}
	if(x==24){
		int bf=y;ans=1;
		rep(i,0,23)if(dif(i,bf)<dif(ans,bf))ans=i;
	}printf("%.2d:%.2d\n",ans,z);
	return 0;
}