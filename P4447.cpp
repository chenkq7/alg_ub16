#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;
const int NMAX = 1e5 + 5;
const int INF = 1e9 + 5;
int a[NMAX], n;

int main(int argc, char const *argv[])
{
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, a);
    sort(a, a + n);
    queue<int> que;
    int num, cnt, ans = INF;
    for (int i = 0; i < n; i++)
    {
        if (que.empty())
        {
            que.push(a[i]);
            num = a[i] + 1;
            cnt = 1;
            continue;
        }
        // invariable: 0<cnt<=que.size()
        if (a[i] < num)
        {
            que.push(a[i]);
            cnt++;
        }
        else if (a[i] == num)
        {
            cnt--;
            if (cnt == 0)
            {
                num++;
                cnt = que.size();
            }
        }
        else
        {
            while (cnt > 0)
            {
                ans = min(ans, num - que.front());
                que.pop();
                cnt--;
            }
            num++;
            cnt = que.size();
            i--;
        }
        // cout << num << " " << cnt << " " << ans << " " << que.size() << " " << a[i] << " " << que.front() << endl;
    }
    while (cnt > 0)
    {
        ans = min(ans, num - que.front());
        que.pop();
        cnt--;
    }
    while (!que.empty())
    {
        ans = min(ans, num - que.front() + 1);
        que.pop();
    }
    cout << ans << endl;
    return 0;
}
