/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Locke Cai
 */

#include <bits/stdc++.h>

#include <bits/stdc++.h>
#define MOD 1000000007

class FProgressMonitoring {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n; in >> n;
        long long dp[n+1][n+1];
        int arr[n];
        for(int i = 0; i<n; i++) in >> arr[i];
        for(int i = 0; i<=n; i++) dp[i][i] = 1;
        for(int len = 1; len <=n; len++){
            for(int i = 0; i+len <= n; i++){
                int j = i+len;
                dp[i][j] = 0;
                for(int k = i+1; k<=j; k++){
                    if(k == j || arr[k] > arr[i]) dp[i][j] = (dp[i][j]+dp[i+1][k]*dp[k][j]%MOD)%MOD;
                }
            }
        }
        out << dp[1][n];
    }
};


int main() {
	FProgressMonitoring solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}