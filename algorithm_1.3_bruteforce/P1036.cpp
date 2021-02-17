#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int NMAX = 20 + 2;
int myints[NMAX];
int results[NMAX];
int n, m, tot;

bool isPrime(int num)
{
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    int bd = sqrt(num);
    for (int i = 3; i <= bd + 1; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void combinations(int *arr, int arrsize, int *result, int len, int left, int begin)
{
    for (int i = begin; i < arrsize - left + 1; i++)
    {
        result[left - 1] = i;
        if (left - 1 == 0)
        {
            int num = 0;
            for (int i = 0; i < len; i++)
            {
                num += arr[results[i]];
            }
            if (isPrime(num))
            {
                tot++;
                // cout << num << endl;
            }
        }
        else
        {
            combinations(arr, arrsize, result, len, left - 1, i + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> myints[i];
    combinations(myints, n, results, m, m, 0);
    cout << tot;
    return 0;
}
