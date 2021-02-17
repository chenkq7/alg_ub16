/**
 * 
 * 1 2 3 4 5 6 7 8 
 1 4 4 3 3 4 4 3 3
 2 4 4 4 3 4 3 3 3
 3 2 4 X 1 3 3 3 1
 4 2 2 1 1 1 3 1 1
 5 4 4 2 1 1 1 3 3
 6 4 * 2 2 1 1 1 3
 7 2 * * 1 2 1 1 1
 8 2 2 1 1 2 2 1 1
 * 
 * * * * * * * * *
 * 
 * 1 2 3 4 5 6 7 8 
 1 4 4 * * * * 3 3
 2 4 ? # ? * * * 3
 3 * # X * * * * *
 4 * ? * ? * * * *
 5 * * * * * * * *
 6 * * * * * * * *
 7 2 * * * * * * 1
 8 2 2 * * * * 1 1
 * 
 * */

#include <iostream>
#include <iomanip>
using namespace std;
#define DEBUG(x) cout << #x << " = " << x << endl

const int NMAX = (1 << 10) + 5;
int map[NMAX][NMAX], n, pos_x, pos_y;
int solve[5][2][2] = {{{0, 0}, {0, 0}},
                      {{-1, 0}, {0, -1}},
                      {{-1, 0}, {0, 1}},
                      {{1, 0}, {0, -1}},
                      {{1, 0}, {0, 1}}};

inline bool canSettle(int x, int y, int i)
{
    return !map[x][y] &&
           x + solve[i][0][0] >= 1 && x + solve[i][0][0] <= n &&
           y + solve[i][0][1] >= 1 && y + solve[i][0][1] <= n &&
           !map[x + solve[i][0][0]][y + solve[i][0][1]] &&
           x + solve[i][1][0] >= 1 && x + solve[i][1][0] <= n &&
           y + solve[i][1][1] >= 1 && y + solve[i][1][1] <= n &&
           !map[x + solve[i][1][0]][y + solve[i][1][1]];
}

inline void settle(int x, int y, int i)
{
    map[x][y] = i;
    map[x + solve[i][0][0]][y + solve[i][0][1]] = -i;
    map[x + solve[i][1][0]][y + solve[i][1][1]] = -i;
}

inline void unsettle(int x, int y, int i)
{
    map[x][y] -= i;
    map[x + solve[i][0][0]][y + solve[i][0][1]] += i;
    map[x + solve[i][1][0]][y + solve[i][1][1]] += i;
}

int dfs(int x, int y)
{
    // cout << "dfs(" << x << ", " << y << ")" << endl;
    if (x > n)
        return 1;
    int next_x = x, next_y = y;
    if (++next_y > n)
        ++next_x, next_y = 1;
    if (map[x][y])
    {
        if (x - 1 >= 1 && !map[x - 1][y])
            return 0;
        return dfs(next_x, next_y);
    }
    // !map[x][y]
    if (x - 1 >= 1 && !map[x - 1][y])
    {
        for (int i = 1; i <= 2; i++)
        {
            if (canSettle(x, y, i))
            {
                // cout << "canSettle(" << x << ", " << y << ", " << i << ")" << endl;
                settle(x, y, i);
                if (dfs(next_x, next_y))
                    return 1;
                unsettle(x, y, i);
            }
        }
        return 0;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (canSettle(x, y, i))
        {
            // cout << "canSettle(" << x << ", " << y << ", " << i << ")" << endl;
            settle(x, y, i);
            if (dfs(next_x, next_y))
                return 1;
            unsettle(x, y, i);
        }
    }
    if (x == n)
        return 0;
    return dfs(next_x, next_y);
}

int main(int argc, char const *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    cin >> n >> pos_x >> pos_y;
    n = 1 << n;
    map[pos_x][pos_y] = 9;
    dfs(1, 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << setw(3) << map[i][j];
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (map[i][j] >= 1 && map[i][j] <= 4)
                cout << i << " " << j << " " << map[i][j] << endl;
    return 0;
}
