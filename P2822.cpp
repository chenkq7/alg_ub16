#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

const int NMAX = 2e3 + 5;
int dp[NMAX][NMAX];
int t, k;
vector<pair<int, int> > vec;
/**
 * 核心观察：
 * 1. 组合数三角即杨慧三角,存在只用加法的递推式
 * 2. 由于k固定,上述加法递推式可在递推过程中求mod,以解决当n过大时,数过大存不下的问题
 * 3. 由于query较多,可以使用前缀和加速.将输出过程的时间复杂度由n^3降到n^2
 * */
int main(int argc, char const *argv[])
{
    // input
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    cin >> t >> k;
    for (int i = 0; i < t; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        vec.push_back(make_pair(tmp1, tmp2));
    }
    // dp
    int n = max_element(vec.begin(), vec.end())->first;
    dp[0][0] = 1 % k;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % k;
    }
    // prefix sum
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = (dp[i][0] == 0);
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i][j - 1] + (dp[i][j] == 0);
    }
    // output
    for (int i = 0; i < t; i++)
    {
        int x = vec[i].first, y = vec[i].second, ans = 0;
        for (int j = 0; j <= x; j++)
            ans += dp[j][min(j, y)];
        cout << ans << endl;
    }
    return 0;
}
