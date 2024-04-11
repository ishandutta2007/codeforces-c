#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
void putint(LL n)
{
     char a[20];
     int size=0;
     if (n==0)
        putchar('0');
     while (n)
     {
           a[size++]=n%10+48;
           n/=10;
     }
     for (int i=size-1;i>=0;i--)
         putchar(a[i]);
     putchar('\n');
}
const int INF=1e9+10;
int n,m,k,x,d[100010],ans,u[100010],v[100010],l[100010];
bool b[100010];
int main()
{
	getint(n);
	getint(m);
	getint(k);
	FOR(i,1,n) d[i]=INF; 
	FOR(i,1,m)
		scanf("%d%d%d",&u[i],&v[i],&l[i]);
	FOR(i,1,k)
	{
		scanf("%d",&x);
		b[x]=1;
	}
	FOR(i,1,m)
	{
		if (!b[u[i]] && b[v[i]])
		{
			if (l[i]<d[u[i]]) d[u[i]]=l[i];
		}
		swap(u[i],v[i]);
		if (!b[u[i]] && b[v[i]])
		{
			if (l[i]<d[u[i]]) d[u[i]]=l[i];
		}
	}
	ans=INF;
	FOR(i,1,n)
		if (!b[i])
			if (d[i]<ans) ans=d[i];
	if (ans<INF) cout<<ans<<endl; else puts("-1");
	return 0;
}