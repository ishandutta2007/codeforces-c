#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=2000005;
ll a[N],ans;
int n;

void rmain(){
	read(n),ans=0;
	rep(i,1,n){
		read(a[i]);
		if(i>=2&&a[i-1]>a[i]){
			ans+=a[i-1]-a[i];
		}
	}
	printf("%lld\n",ans);
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();

	return 0;
}