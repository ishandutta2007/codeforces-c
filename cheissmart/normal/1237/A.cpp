#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[14000];

int32_t main()
{
	IO_OP;
	
	int n;
	vi v;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(a[i]%2 == 0) a[i] /= 2;
		else v.PB(i);
	}
	for(int i=0;i<v.size()/2;i++)
		a[v[i]] = floor(a[v[i]]/2.);
	for(int i=v.size()/2;i<v.size();i++)
		a[v[i]] = ceil(a[v[i]]/2.);
	for(int i=0;i<n;i++)
		cout << a[i] << endl;
}