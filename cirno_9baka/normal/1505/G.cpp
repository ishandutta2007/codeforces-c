#include<bits/stdc++.h>
using namespace std;
int f[105],n,m,i,j,x,y,ans,a[5];
vector<int> t[26]
={{1,0,0,1,0},
{1,1,0,2,0},
{2,0,0,1,1},
{2,1,0,1,2},
{1,1,0,1,1},
{2,1,0,2,1},
{2,2,0,2,2},
{1,2,0,2,1},
{1,1,0,1,1},
{1,2,0,1,2},
{1,0,1,2,0},
{1,1,1,3,0},
{2,0,1,2,1},
{2,1,1,2,2},
{1,1,1,2,1},
{2,1,1,3,1},
{2,2,1,3,2},
{1,2,1,3,1},
{1,1,1,2,1},
{1,2,1,2,2},
{1,0,2,2,1},
{1,1,2,3,1},
{1,2,1,1,3},
{2,0,2,2,2},
{2,1,2,2,3},
{1,1,2,2,2}};
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
    	scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
    	for(j=0;j<26;++j)
    		if(a[0]==t[j][0]&&a[1]==t[j][1]&&a[2]==t[j][2]&&a[3]==t[j][3]&&a[4]==t[j][4])
    		{
				putchar(j+'a');
    			break;
    		}
	}
}