#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,i,h,w,a[50005],b[50005],k,ans[50005],m,s[4],t,sa,sb,ty,j;
char c1[50005],c2[50005];
bool flag;
void rev(int a[],int p)
{
	if(p<0)
		return;
	int i;
	ans[++m]=p;
	p++;
	for(i=0;i*2<p;i++)
		swap(a[i],a[p-i-1]);
	for(i=0;i<p;i++)
		if(a[i]==1)
			a[i]=2;
		else
			if(a[i]==2)
				a[i]=1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s\n%s",c1,c2);
		n=strlen(c1)/2;
		memset(s,0,sizeof(s));
		for(i=0;i<n;i++)
		{
			a[i]=(c1[i*2]-'0')*2+c1[i*2+1]-'0';
			s[a[i]]++;
		}
		for(i=0;i<n;i++)
		{
			b[i]=(c2[i*2]-'0')*2+c2[i*2+1]-'0';
			s[b[i]]--;
		}
		if(s[0]!=0||s[3]!=0)
		{
			printf("-1\n");
			continue;
		}
		sa=sb=0;
		m=ty=0;
		for(i=0;i<n;i++)
			if(b[i]==2)
				ty++;
		for(i=0;i<n;i++)
			if(a[i]==1)
				sb++;
		for(i=0;i<n;i++)
		{
			if(a[i]==2)
				sa++;
			if(a[i]==1)
				sb--;
			if(sa+sb==ty)
			{
				rev(a,i);
				break;
			}
		}
		flag=false;
		if(m==0)
		{
			sa=sb=ty=0;
			for(i=0;i<n;i++)
				if(a[i]==2)
					ty++;
			for(i=0;i<n;i++)
				if(b[i]==1)
					sb++;
			for(i=0;i<n;i++)
			{
				if(b[i]==2)
					sa++;
				if(b[i]==1)
					sb--;
				if(sa+sb==ty)
				{
					rev(b,i);
					break;
				}
			}
			if(m!=0)
				flag=true;
		}
		ty=n-1;
		for(i=0;ty>=0;i++,ty--)
		{
			for(j=i;j<n;j++)
				if((a[j]==1&&b[ty]==2)||(a[j]==2&&b[ty]==1)||(a[j]==0&&b[ty]==0)||(a[j]==3&&b[ty]==3))
				{
					rev(a,j-1);
					rev(a,j);
					break;
				}
		}
		if(flag)
		{
			printf("%d\n",m);
			for(i=2;i<=m;i++)
				printf("%d ",ans[i]*2+2);
			printf("%d\n",ans[1]*2+2);
		}
		else
		{
			printf("%d\n",m);
			for(i=1;i<=m;i++)
				printf("%d ",ans[i]*2+2);
			printf("\n");
		}
	}
}