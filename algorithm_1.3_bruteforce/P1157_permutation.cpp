#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
const int NMAX = 21 + 5;
int n, r, myints[NMAX];

int main(int argc, char const *argv[])
{
    cin >> n >> r;
    for (int i = r + 1; i <= n; i++)
        myints[i] = 1;
    do
    {
        for (int i = 1; i <= n; i++)
        {
            if (!myints[i])
                cout << setw(3) << i;
        }
        cout << endl;
    } while (next_permutation(myints + 1, myints + n + 1));

    return 0;
}
