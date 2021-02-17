#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int final[10];

void decode_solve(int num)
{
    for (int i = 0; i < 10; i++)
        final[i] = 1;
    int idx = 9;
    while (num)
    {
        final[idx] += num % 3;
        num /= 3;
        idx -= 1;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n < 10 || n > 30)
    {
        cout << 0;
        return 0;
    }
    int minBound = 0;
    int maxBound = 0;
    int po = 1;
    for (int i = 0; i < 10; i++)
    {
        maxBound += 2 * po;
        po *= 3;
    }
    int cnt = 0;
    for (int i = minBound; i <= maxBound; i++)
    {
        decode_solve(i);
        if (accumulate(&final[0], &final[10], 0) == n)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = minBound; i <= maxBound; i++)
    {
        decode_solve(i);
        if (accumulate(&final[0], &final[10], 0) == n)
        {
            for (int i = 0; i < 10; i++)
                cout << final[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
