#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int NMAX = 20 + 5;

bool used[NMAX][NMAX][NMAX];
ll dp[NMAX][NMAX][NMAX];

ll mem_search(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return mem_search(20, 20, 20);
    if (used[a][b][c])
        return dp[a][b][c];
    used[a][b][c] = 1;
    if (a < b && b < c)
        dp[a][b][c] = mem_search(a, b, c - 1) + mem_search(a, b - 1, c - 1) - mem_search(a, b - 1, c);
    else
        dp[a][b][c] = mem_search(a - 1, b, c) + mem_search(a - 1, b - 1, c) + mem_search(a - 1, b, c - 1) - mem_search(a - 1, b - 1, c - 1);
    return dp[a][b][c];
}

int main(int argc, char const *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    ll x, y, z;
    while (1)
    {
        cin >> x >> y >> z;
        if (x == -1 && y == -1 && z == -1)
            break;
        cout << "w(" << x << ", " << y << ", " << z << ") = " << mem_search(x, y, z) << endl;
    }

    return 0;
}
