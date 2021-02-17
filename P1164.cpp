#include <iostream>
using namespace std;

const int MMAX = 1e4 + 5;
int dp[MMAX];

int main(int argc, char const *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int n, m, value;
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> value;
        for (int j = m; j >= value; j--)
            dp[j] += dp[j - value];
    }
    cin >> value;
    dp[m] += dp[m - value];
    cout << dp[m] << endl;
    return 0;
}
