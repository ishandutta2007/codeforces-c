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
LL ans;
int n,m,b[2222],d[2222],c[2222],a[2222];
int main()
{
	scanf("%d%d",&n,&m);
	FOR(i,1,n){
		getint(a[i]);
		if (a[i]<=m) b[a[i]]++;
	}
	FOR(i,1,n){
		if (a[i]>m) c[i]=1; else d[a[i]]++;
		if (a[i]<=m) if (d[a[i]]>n/m) d[a[i]]--,c[i]=1;
	}
	FOR(i,1,m)
		if (d[i]<n/m){
			FOR(j,1,n) if (c[j]==1){
				a[j]=i,ans++,c[j]=0,d[i]++;
				if (d[i]==n/m) break;
			}
		}
	cout<<n/m<<' '<<ans<<endl;
	FOR(i,1,n) cout<<a[i]<<' ';
	return 0;
}