#include<bits/stdc++.h>
using namespace std;
int n,m,a[505][505],i,j,k,visx[505],visy[505],l,p[500005],mxx[505],mxy[505],tot,ans[505][505],lx,ly,x,y;
int Nex()
{
	while(p[l])
		++l;
	p[l]=1;
	return l;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			mxx[i]=max(mxx[i],a[i][j]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			mxy[j]=max(mxy[j],a[i][j]);
	sort(mxx+1,mxx+1+n);
	sort(mxy+1,mxy+1+m);
	mxx[n+1]=mxy[m+1]=1<<30;
	lx=ly=1;
	x=n,y=m;
	while(lx<=n||ly<=m)
		if(mxx[lx]<mxy[ly])
			ans[x--][y]=mxx[lx++];
		else
			if(mxx[lx]>mxy[ly])
				ans[x][y--]=mxy[ly++];
			else
			{
				ans[x--][y--]=mxx[lx++];
				++ly;
			}
	l=tot;
	for(i=1;i<=n;++i)
	{
		p[mxx[i]]=1;
		if(!visx[i])
			ans[++l][tot]=mxx[i];
	}
	l=tot;
	for(i=1;i<=m;++i)
	{
		p[mxy[i]]=1;
		if(!visy[i])
			ans[tot][++l]=mxy[i];
	}
	l=1;
	for(i=1;i<=n*m;++i)
		if(p[i])
		{
			int x=0,y=0;
			for(j=1;j<=n;++j)
				for(k=1;k<=m;++k)
					if(ans[j][k]==i)
					{
						x=j;
						y=k;
						break;
					}
			for(j=x-1;!ans[j][y]&&j>=1;--j);
			for(++j;j<x;++j)
				if(!ans[j][y])
					ans[j][y]=Nex();
			for(j=x+1;!ans[j][y]&&j<=n;++j);
			for(--j;j>x;--j)
				if(!ans[j][y])
					ans[j][y]=Nex();
			for(j=y-1;!ans[x][j]&&j>=1;--j);
			for(++j;j<y;++j)
				if(!ans[x][j])
					ans[x][j]=Nex();
			for(j=y+1;!ans[x][j]&&j<=m;++j);
			for(--j;j>y;--j)
				if(!ans[x][j])
					ans[x][j]=Nex();
		}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}