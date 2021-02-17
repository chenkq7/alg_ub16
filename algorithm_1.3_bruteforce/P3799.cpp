#include <iostream>
#include <algorithm>
// #define DEBUG(x) cout << #x " = " << x << endl
#define DEBUG(x) ;
using namespace std;
typedef long long ll;
const int NMAX = 5e3 + 5;
const int MOD = 1e9 + 7;

int n, maxElem;
ll synthesis[NMAX], cnt[NMAX];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
        maxElem = max(maxElem, tmp);
    }
    for (int i = 0; i <= maxElem; i++)
    {
        for (int j = i; i + j <= maxElem; j++)
        {
            if (cnt[i] && cnt[j])
            {
                if (i == j)
                    synthesis[i + j] += cnt[i] * (cnt[i] - 1) / 2;
                else
                    synthesis[i + j] += cnt[i] * cnt[j];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= maxElem; i++)
    {
        DEBUG(i);
        DEBUG(cnt[i]);
        DEBUG(synthesis[i]);
        if (cnt[i] >= 2 && synthesis[i] >= 1)
        {
            ans += ((cnt[i] - 1) * cnt[i] / 2 * synthesis[i]);
            ans %= MOD;
            DEBUG(ans);
        }
    }
    cout << ans << endl;
    return 0;
}
