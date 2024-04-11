#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int INF=1e9+7;
int T;
int a[N];
bool vis[N];
int main(){
	scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		rep0(i,n){
			scanf("%d",&a[i]);
			vis[i]=0;
			a[i]=((a[i]+i)%n+n)%n;
		}
		bool fl=0;
		rep0(i,n){
			if(vis[i])continue;
			vis[i]=1;
			for(int j=a[i];j!=i;j=a[j]){
				if(vis[j]){
					fl=1;
					break;
				}
				vis[j]=1;
			}
			if(fl)break;
		}
		if(fl)puts("NO");
		else puts("YES");
	}
	return 0;
}