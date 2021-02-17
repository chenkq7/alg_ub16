#include <iostream>
#include <cmath>
using namespace std;
const int UNITY_H = 2;
const int UNITY_W = 4;
char unity[UNITY_H][UNITY_W] = {' ', '/', '\\', ' ', '/', '_', '_', '\\'};
char map[1024][2048];

void print_map(int x, int y, int level)
{
    if (level == 1)
    {
        for (int i = 0; i < UNITY_H; i++)
            for (int j = 0; j < UNITY_W; j++)
                map[x + i][y + j] = unity[i][j];
        return;
    }
    int height = pow(2, level), length = 2 * pow(2, level);
    print_map(x, y + length / 4, level - 1);
    print_map(x + height / 2, y, level - 1);
    print_map(x + height / 2, y + length / 2, level - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    print_map(0, 0, n);
    int height = pow(2, n), length = 2 * pow(2, n);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (!map[i][j])
                cout << " ";
            else
                cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}
