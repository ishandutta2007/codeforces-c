#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(i=a;i<b;i++)

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t;
	string s,temp;
		cin>>t;
		while(t--)
		{
			s.clear();
			temp.clear();
			cin>>s;
			if(s.length()>=2)
			{
				temp=s.substr(s.length()-2,2);
				if(temp=="po")
				{
					cout<<"FILIPINO\n";continue;
				}
			}
			if(s.length()>=4)
			{
				temp=s.substr(s.length()-4,4);
				if(temp=="desu" || temp=="masu")
				{
					cout<<"JAPANESE\n";continue;
				}
			}
			if(s.length()>=5)
			{
				temp=s.substr(s.length()-5,5);
				if(temp=="mnida")
				{
					cout<<"KOREAN\n";continue;
				}
			}
		}	
	return 0;
}