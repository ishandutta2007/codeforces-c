#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int n, x, y;
	string s;
	cin >> n >> x >> y >> s; 
	reverse(s.begin(), s.end());
	int ans = 0;
	for(int i=0;i<x;i++) {
		if(i == y)
			ans += s[i] != '1';
		else
			ans += s[i] != '0';
	}
	cout << ans << endl;
}