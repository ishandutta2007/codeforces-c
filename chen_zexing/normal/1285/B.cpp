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
int a[100005];
long long pre[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        long long mx=0,mn=0;
        for(int i=1;i<n;i++){
            mx=max(mx,pre[i]-mn);
            mn=min(mn,pre[i]);
        }
        for(int i=1;i<n;i++) mx=max(mx,pre[n]-pre[i]);
        if(pre[n]>mx) puts("YES");
        else puts("NO");
    }
    return 0;
}