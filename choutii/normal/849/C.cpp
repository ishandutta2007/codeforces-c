#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

int K;
int main() {
	int i;
	cin >> K; 
	if(!K) {
		puts("a");
	}
	else
		for(int c = 0; K && c < 26; c++) {
			char ch = c + 'a';
			for(i = 1; i * (i - 1) / 2 <= K; i++); i--;
			K -= i * (i - 1)/2;
			for(int o = 1; o <= i; o++)
				putchar(ch);
		}
	return 0;
}