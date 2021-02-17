#include <iostream>
#include <iomanip>
using namespace std;
const int NMAX = 21 + 5;
int n, r, result[NMAX];

void combinations(int idx, int begin)
{
    if (idx == r)
    {
        for (int i = 0; i < r; i++)
            cout << setw(3) << result[i];
        cout << endl;
        return;
    }
    for (int i = begin; r - 1 - idx <= n - i /*剩下的数多(等)于格子数*/; i++)
    {
        result[idx] = i;
        combinations(idx + 1, i + 1);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> r;
    combinations(0, 1);
    return 0;
}
