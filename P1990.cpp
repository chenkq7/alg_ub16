#include <iostream>
using namespace std;

const int NMAX = 1e6 + 5;
const int MOD = 1e4;

int f[NMAX], g[NMAX];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    f[0] = 1, g[0] = 0;
    f[1] = 1, g[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i - 2] + f[i - 1] + g[i - 2] * 2) % MOD;
        g[i] = (f[i - 1] + g[i - 1]) % MOD;
    }
    cout << f[n] << endl;
    return 0;
}

/**
 * dp按照结尾处形状做讨论：
 * f数组存放结尾平的方案数，g数组存结尾向一个特定方向凸的方案数。有如下递推关系。
 * ?|(n) = ?|(n-2)=  ?|(n-1)|  ?L(n-2)T*2
 * ?L(n) = ?L(n-1)-  ?|(n-1)L  
 * */