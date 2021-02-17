#include <bits/stdc++.h>
using namespace std;
int a[5], i, j, k, sum, t, homework[21], dp[2501];

/**
 * dp[k][j] 为在总重不超过 k 时，在前j个物品中，选出若干，所能获得的收益最多。
 * dp[k][j] = max(dp[k-v[j]][j-1]+v[j], dp[k][j-1])
 * 初值: dp[0..maxWeight][0] = 0
 * 可以使用适当的顺序，将空间压缩至一维数组: 即从后向前扫描。（从数据依赖图中可以很容易看出。所有边指向右下方向
 * * * 在这个题目中收益和重量相等。
 * 
 * * * 本题目一个重要观察： 
 * * * 左脑小于等于且最接近总时间一半时，右脑即为该任务的解。
 * * * 所以，就是要求，在消耗时间不超过 sum/2 时，选出若干任务，所消耗的时间最多。
*/
int main()
{
    for (i = 1; i <= 4; i++)
        cin >> a[i];
    for (i = 1; i <= 4; i++)
    {
        sum = 0;
        for (j = 1; j <= a[i]; j++)
        {
            cin >> homework[j];
            sum += homework[j];
        }
        for (j = 1; j <= a[i]; j++)
            for (k = sum / 2; k >= homework[j]; k--)                   //只要是总和的一半
                dp[k] = max(dp[k], dp[k - homework[j]] + homework[j]); //01背包
        t += sum - dp[sum / 2];                                        //累加为另一个脑子
        for (j = 1; j <= sum / 2; j++)
            dp[j] = 0; //清零
    }
    cout << t;
    return 0;
}