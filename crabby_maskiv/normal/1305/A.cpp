#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int inf=0x3f3f3f3f;
int n,m;
int a[N],b[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
		for(i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;
	}
	return 0;
}