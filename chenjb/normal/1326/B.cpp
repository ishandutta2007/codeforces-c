#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
long long a[510000],b[510000];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	long long now=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i]+now;
		now=max(now,a[i]);
	}
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	puts("");
	return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		scanf("%d",&n);
		if (n==1){ puts("-1"); continue; }
		int opt=2*(n-1)%3;
		if (opt==0)
		{
			for(int i=1;i<=n-2;i++)putchar('2');
			puts("33");
		}
		else
		{
			for(int i=1;i<=n-1;i++)putchar('2');
			puts("3");
		}
	}
	return 0;
}
*/