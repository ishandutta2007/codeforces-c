#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005;
int n, cnt, a[N], b[N], f[N], g[N], ff[N], gg[N];
pair<pair<int,int>,pair<int,int>> ans[N];
int main() {
	scanf("%d", &n);
	for(int i=1, x; i<=n; ++i) scanf("%d", &x), a[x]=f[i]=g[i]=ff[i]=gg[i]=i;
	for(int i=1, x; i<=n; ++i) scanf("%d", &x), b[x]=i;
	for(int i=1; i<=n; ++i){
		if(a[i]!=f[i] || b[i]!=g[i]){
			int x=ff[a[i]], y=gg[b[i]];
			ans[cnt++]=make_pair(make_pair(x, i), make_pair(i, y));
			swap(f[i], f[x]), swap(ff[f[i]], ff[f[x]]);
			swap(g[i], g[y]), swap(gg[g[i]], gg[g[y]]);
		}
	}
	printf("%d\n", cnt);
	for(int i=0; i<cnt; ++i) printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
	return 0;
}