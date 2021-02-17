#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 250 + 5;
char value[NMAX];
int prev[NMAX], next[NMAX], k;

int main(int argc, char const *argv[])
{
    scanf("%s%d", value + 1, &k);
    int len = strlen(value + 1);
    value[0] = value[len + 1] = '0' - 1;
    prev[0] = next[len + 1] = -1;
    for (int i = 1; i <= len + 1; i++)
        next[i - 1] = i, prev[i] = i - 1;
    int ind = next[0];
    while (k--)
    {
        while (1)
        {
            if (value[ind] > value[next[ind]])
                break;
            ind = next[ind];
        }
        next[prev[ind]] = next[ind];
        prev[next[ind]] = prev[ind];
        ind = prev[ind];
    }
    ind = next[0];
    while (value[ind] == '0')
        ind = next[ind];
    if (value[ind] == '0' - 1)
        putchar('0');
    else
    {
        while (value[ind] != '0' - 1)
        {
            putchar(value[ind]);
            ind = next[ind];
        }
    }
    return 0;
}
