#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(long long i=1;i<=n;++i)
#define bit(i) __builtin_popcountll(i)
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
#define N 110000
#define inf 1000000
#define pow fuck
using namespace std;
int n;
long long a[310000];
char s[310000];
int f[310000][2][2][2][2];
map<int,int> dic;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)s[n+i]=s[i];
    	int flag=0;
    	for(int i=1;i<=n;i++)
    		if (s[i]!=s[1]){ flag=i; break; }
    	if (flag==0)
    	{
    		printf("%d\n",(n-1)/3+1);
    		continue;
    	}
    	int ans=0,cnt=0;

    	for(int i=flag;i<n+flag;i++)
    	{
    		if(s[i]!=s[i-1])
        	{
           	 	ans+=cnt/3;
            	cnt=1;
            	continue;
        	}
        	cnt++;
    	}
    	ans += cnt / 3;
    	printf("%d\n",ans);
	}
	return 0;
}