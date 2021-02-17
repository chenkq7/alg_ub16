#include <iostream>
using namespace std;
typedef unsigned long long ull;
const int NMAX = 5e3 + 5;
ull dp[NMAX];
/**
 * 精读不足，需要手写高精度
*/
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 2] + dp[i - 1];
    cout << dp[n];
    return 0;
}
