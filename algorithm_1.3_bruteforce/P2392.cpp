#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define DEBUG(x) cout << #x " = " << x << endl

vector<int> vec;

/**
 * @brief brute-force search
*/
int solve_min_time_bf(int left, int sum_zero, int sum_one)
{
    if (left == 0)
        return max(sum_one, sum_zero);
    return min(solve_min_time_bf(left - 1, sum_zero + vec[left - 1], sum_one),
               solve_min_time_bf(left - 1, sum_zero, sum_one + vec[left - 1]));
}

/**
 * @brief dp search
 * 
 * 
 * 
*/
int solve_min_time_dp()
{
}

int main(int argc, char const *argv[])
{
    int nums[4];
    for (int i = 0; i < 4; i++)
        cin >> nums[i];
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        vec.clear();
        for (int j = 0; j < nums[i]; j++)
        {
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        int tmp = solve_min_time_bf(nums[i], 0, 0);
        // DEBUG(tmp);
        ans += tmp;
    }
    cout << ans;
    return 0;
}
