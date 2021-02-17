#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int stl_main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 1; i <= n; i++)
        vec.push_back(i);
    do
    {
        for (auto item : vec)
            cout << setw(5) << item;
        cout << endl;
    } while (next_permutation(vec.begin(), vec.end()));

    return 0;
}

const int NMAX = 10;
int n, path[NMAX], used[NMAX];
void dfs(int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
            cout << setw(5) << path[i];
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            path[idx] = i;
            dfs(idx + 1);
            used[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    cin >> n;
    dfs(0);
    return 0;
}
