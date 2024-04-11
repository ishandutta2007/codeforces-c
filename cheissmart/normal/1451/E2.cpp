#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << (x) << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1 << 16;

int x[N], a[N];

int XOR(int i, int j) {
	i++, j++;
	cout << "XOR " << i << " " << j << endl;
	int k;
	cin >> k;
	return k;
}
int AND(int i, int j) {
	i++, j++;
	cout << "AND " << i << " " << j << endl;
	int k;
	cin >> k;
	return k;
}
int OR(int i, int j) {
	i++, j++;
	cout << "OR " << i << " " << j << endl;
	int k;
	cin >> k;
	return k;
}

int cnt[N];

signed main()
{
//	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i < n; i++)
		x[i] = XOR(0, i);
	int who = -1;
	for(int i = 0; i < n; i++) {
		cnt[x[i]]++;
		if(cnt[x[i]] == 2) {
			who = x[i];
			break;
		}	
	}
	int tt = 0;
	if(who != -1) {
		int ii = -1, jj = -1;
		for(int i = 0; i < n; i++) {
			if(x[i] == who) {
				if(ii == -1) ii = i;
				else jj = i;
			}
			if(jj != -1) break;
		}
		tt = x[ii] ^ AND(ii, jj);
	} else {
		int k = __lg(n);
		int ii = -1, jj = -1;
		for(int i = 0; i < n; i++) {
			if(x[i] == 1) {
				ii = i;
			} else if(x[i] == (1 << k) - 2) {
				jj = i;
			}
		}
		int a01 = AND(0, ii);
		int a02 = AND(0, jj);
		for(int j = 0; j < k; j++) {
			int b1 = x[ii] >> j & 1;
			int b2 = x[jj] >> j & 1;
			if(b1 == 0) {
				tt |= (a01 >> j & 1) << j;
			} else if(b2 == 0) {
				tt |= (a02 >> j & 1) << j;
			} else {
				throw;
			}
		}
	}
	for(int i = 0; i < n; i++) a[i] = x[i] ^ tt;
	cout << "!";
	for(int i = 0; i < n; i++) cout << " " << a[i];
	cout << endl;
}