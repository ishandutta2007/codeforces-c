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

vi G[33];
int a[100005];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		for(int j=0;j<=30;j++)
			if(a[i]>>j&1)
				G[j].PB(i);
	}
	for(int i=30;i>=0;i--) {
		if(G[i].size() == 1) {
			swap(a[0], a[G[i][0]]);
			break;
		}
	}
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
}