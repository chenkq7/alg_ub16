#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if (x < y)
        return gcd(y, x);
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int ans = 1;
    // 卡特兰递推式1
    for (int i = 0; i < n; i++)
    {
        int _gcd = gcd(4 * i + 2, i + 2);
        ans = ans / ((i + 2) / _gcd) * ((4 * i + 2) / _gcd);
    }
    cout << ans << endl;
    return 0;
}
