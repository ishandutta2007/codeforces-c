#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[105],f[105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!f[i]){
                ans++;
                for(int j=i+1;j<=n;j++)
                    if(a[j]%a[i]==0)
                        f[j]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp