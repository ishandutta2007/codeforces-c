#include<cstdio>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
const int o=110;
int T,n,m,ans;char s[o][o];
int main(){
	read(T);while(T--){read(n);read(m);for(int i=1;i<=n;++i) scanf("%s",s[i]+1);ans=0;
	for(int i=1;i<=m;++i) ans+=(s[n][i]=='D');for(int i=1;i<=n;++i) ans+=(s[i][m]=='R');write(ans);putchar('\n');}
	return 0;
}