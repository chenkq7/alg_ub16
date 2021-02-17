#include <iostream>
using namespace std;

const int NMAX = 20;

int dp[NMAX][NMAX];

/**
 * 核心观察：
 * 1. 操作序列 和 输出的操作数序列 一一对应
 * 2. push/pop操作可以用+(1,0),+(0,1)表示，操作序列即是从(0,0)到(n,n)的路径。
 *      路径上各点(x,y)需满足x>=y.
 * dp[i][j] 表示 从 (0,0)到该点(i,j) 的路径数
 * */
int mem_search(int push, int pop)
{
    if (push == 0)
        return 1;
    if (!dp[push][pop])
    {
        dp[push][pop] = mem_search(push - 1, pop);
        if (push != pop)
            dp[push][pop] += mem_search(push, pop - 1);
    }
    return dp[push][pop];
}

/**
 * 该数该有一个对应的 组合问题： 卡特兰数
 * 更多参考：https://en.wikipedia.org/wiki/Catalan_number
 * */
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << mem_search(n, n);
    return 0;
}
