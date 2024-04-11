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

int n, x;

bool nok[530000];

int main()
{
	IO_OP;
	
	cin >> n >> x;
	nok[x] = 1;
	for(int i=1;i<(1<<n);i++) {
		if(nok[i]) continue;
		nok[i^x] = 1;
	}
	vi p, ans;
	p.PB(0);
	for(int i=1;i<(1<<n);i++)
		if(!nok[i])
			p.PB(i);
	for(int i=1;i<p.size();i++)
		ans.PB(p[i]^p[i-1]);
	cout << ans.size() << endl;
	for(int e:ans)
		cout << e << " "; 
}