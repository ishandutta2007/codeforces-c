#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=200005;
const int inf=0x3f3f3f3f;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
inline void print(int x) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10);putchar(x%10+'0');
}
int n,m;
int a[maxn];
int vis[maxn];
int dp[maxn];
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	#ifdef TIME
		clock_t ST=clock();
	#endif
	sort(a+1,a+n+1);
	int p=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]) p++;
		vis[p]++;
	}
	sort(vis+1,vis+p+1);
	for(i=1;i<=p;i++)
	{
		for(j=vis[i];j>=1;j--)
		{
			dp[j]=max(dp[j],j);
			if(!(j%2)) dp[j]=max(dp[j/2]+j,dp[j]);
		}
	}
	int ans=0;
	for(i=0;i<maxn;i++) ans=max(ans,dp[i]);
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}