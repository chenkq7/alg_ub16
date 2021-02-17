#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define DEBUG(x) cout << #x " = " << x << endl
const int NMAX = 10 + 5;
const int INF = 1e9 + 5;
int n, acid[NMAX], bitter[NMAX];

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> acid[i] >> bitter[i];
    int minValue = INF;
    for (int i = 1; i < pow(2, n); i++)
    {
        int atmp = 1, btmp = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                atmp *= acid[j];
                btmp += bitter[j];
            }
        }
        if (abs(atmp - btmp) < minValue)
            minValue = abs(atmp - btmp);
    }
    cout << minValue;
    return 0;
}
