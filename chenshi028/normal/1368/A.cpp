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
int t,a,b,n;
int main(){
	read(t);
	while(t--){read(a);read(b);read(n);for(int i=0;;++i,a+=b) if(a>n||b>n){write(i);putchar('\n');break;} else if(a>b) a^=b^=a^=b;}
	return 0;
}