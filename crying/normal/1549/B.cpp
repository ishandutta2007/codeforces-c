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
ll T,n,ans,tag[MAXN];
deque<int>l,r;
char s[3][MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		rep(i,1,2)cin>>(s[i]+1);
		rep(i,1,n){
			tag[i]=0;
			if(s[2][i]=='0')continue;
			if(s[1][i]!='1')ans++;
		}
		rep(i,1,n){
			if(s[1][i]=='0' && s[2][i]=='1')continue;
			if(s[2][i]=='1'){
				if(i!=1 && s[1][i-1]=='1' && !tag[i-1]){
					ans++;
					tag[i-1]=1;
				}else if(i!=n && s[1][i+1]=='1' && !tag[i+1]){
					ans++;
					tag[i+1]=1;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
/*
1
4
1111
1111
*/