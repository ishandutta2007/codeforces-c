#include<cstdio>
#include<cstring>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Max(int a,int b){return a>b?a:b;}
int T,n,ans;char s[100];
int main(){
	for(read(T);T--;putchar('\n')){
		scanf("%s",s+1);
		ans=0;n=strlen(s+1);
		for(int i=1;i<=n;++i) ans=Max(ans,s[i]-48);
		write(ans);
	}
	return 0;
}