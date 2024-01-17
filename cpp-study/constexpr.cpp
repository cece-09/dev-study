#include <iostream>
#include <vector>

using namespace std;
constexpr long fibo_re(long n) {
    return n <= 2 ? 1 : fibo_re(n-1) + fibo_re(n-2);
}

long fibo_dp(long n) {
    if(n <= 2)
        return 1;

    vector<int> dp = {0, 1, 1};
    for(int i = 3; i <= n; ++i)
        dp.push_back(dp[i-1] + dp[i-2]);

    return dp[n];   
}

int main() {
    cout << "recursive" << endl;
    cout << fibo_re(10) << endl;

    cout << "dynamic programming" << endl;
    cout << fibo_dp(10) << endl;

}