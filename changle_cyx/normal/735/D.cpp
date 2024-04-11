#include <bits/stdc++.h>

inline bool is_prime(int n)
{
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false; 
	return true; 
}

int main()
{
	int n; 
	std::cin >> n; 
	if (n == 1 || is_prime(n))
		puts("1"); 
	else if (n % 2 == 0 || is_prime(n - 2))
		puts("2"); 
	else
		puts("3"); 
	return 0; 
}