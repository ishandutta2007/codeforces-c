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
int n,m;
void solve(int r){
	int nxt=n-r+1;
	rep(j,1,(r==nxt)?(m+1)/2:m){
		int nxtj=m-j+1;
		printf("%d %lld\n",r,j);
		if(nxt != r || nxtj !=j){
			printf("%d %d\n",nxt,nxtj);
		}
	}
}
int main(){
	cin>>n>>m;
	rep(i,1,(n+1)/2){
		solve(i);
	}

	return 0;
}