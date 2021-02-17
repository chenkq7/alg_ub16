#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
typedef unsigned long long ll;
const int NMAX = 300 + 5;

ll a[NMAX], n;

int main(int argc, char const *argv[])
{
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, a + 1);
    sort(a + 1, a + n + 1);
    ll i = 0, j = n, ans = 0, flag = 1;
    while (i < j)
    {
        ans += (a[j] - a[i]) * (a[j] - a[i]);
        if (flag)
            ++i;
        else
            --j;
        flag = 1 - flag;
    }
    cout << ans;
    return 0;
}
