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
const int MAXN=110;
ll T,n,val[MAXN][MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(even(n) && n==2){
			printf("-1\n");
			continue;
		}else{
			memset(val,0,sizeof val);
			ll start=1,end=(n*n+1)/2+1;
			rep(i,1,n){
				rep(j,1,n){
					if(even((i+j))){
						val[i][j]=start++;
					}else{
						val[i][j]=end++;
					}
				}
			}
			rep(i,1,n){
				rep(j,1,n){
					printf("%lld ",val[i][j]);
				}
				printf("\n");
			}
		}
		
	}

	return 0;
}