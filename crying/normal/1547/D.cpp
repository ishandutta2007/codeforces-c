#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
ll T,n,x[MAXN],y[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n){
			cin>>x[i];
		}
		y[1]=0;
		rep(i,2,n){
			y[i]=0;
			ll pre=x[i-1]^y[i-1];	
			//pre in x[i]^y[i]
			per(j,29,0){
				if(pre&(1<<j)){
					if(!(x[i]&(1<<j))){
						y[i]+=(1<<j);
					}
				}
			}
		}
		rep(i,1,n)printf("%lld ",y[i]);
		printf("\n");
	}
	
	return 0;
}