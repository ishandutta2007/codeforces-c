#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int n,l,a,x[100005],y[100005],ans;
int main() {
	read(n),read(l),read(a);
	for(int i=1;i<=n;++i)
		read(x[i]),read(y[i]),y[i]+=x[i];
	x[n+1]=l,y[0]=0;
	for(int i=1;i<=n+1;++i)
		ans+=(x[i]-y[i-1])/a;
	cout<<ans;
}