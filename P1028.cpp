#include <iostream>

using namespace std;

const int NMAX = 1e3 + 5;
int dp[NMAX];

int mem_search(int num)
{
    if (!dp[num])
    {
        dp[num] = 1;
        for (int i = 1; i <= num / 2; i++)
            dp[num] += mem_search(i);
    }
    return dp[num];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << mem_search(n);
    return 0;
}
