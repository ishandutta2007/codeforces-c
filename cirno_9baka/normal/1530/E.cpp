#include<bits/stdc++.h>
using namespace std;
const int M=998244353,L=5000,N=1000005;
int n,i,t,m,j,s[26];
char c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c+1);
		memset(s,0,sizeof(s));
		for(i=1;c[i];++i)
			++s[c[i]-'a'];
		for(i=0;i<26;++i)
			if(s[i]==1)
				break;
		if(i<26)
		{
			putchar(i+'a');
			--s[i];
			for(i=0;i<26;++i)
				while(s[i]--)
					putchar(i+'a');
			putchar('\n');
			continue;
		}
		for(i=0;i<26;++i)
			if(s[i])
				break;
		int x=i,su=0;
		for(i=0;i<26;++i)
			if(i!=x)
				su+=s[i];
		if(su+2>=s[x])
		{
			putchar(x+'a');
			--s[x];
			for(i=0;i<26;++i)
				if(i!=x)
					while(s[i]--)
					{
						if(s[x])
						{
							putchar(x+'a');
							--s[x];
						}
						putchar(i+'a');
					}
			while(s[x]--)
				putchar(x+'a');
			putchar('\n');
			continue;
		}
		putchar(x+'a');
		--s[x];
		for(i=x+1;i<26;++i)
			if(s[i])
				break;
		int y=i;
		if(i==26)
		{
			while(s[x]--)
				putchar(x+'a');
			putchar('\n');
			continue;
		}
		putchar(y+'a');
		--s[y];
		for(i=y+1;i<26;++i)
			if(s[i])
				break;
		if(i==26)
		{
			while(s[y]--)
				putchar(y+'a');
			while(s[x]--)
				putchar(x+'a');
			putchar('\n');
			continue;
		}
		else
		{
			while(s[x]--)
				putchar(x+'a');
			--s[i];
			putchar(i+'a');
			for(i=x+1;i<26;++i)
				while(s[i]--)
					putchar(i+'a');
			putchar('\n');
			continue;
		}
	}
}