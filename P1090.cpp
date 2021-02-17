#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> que;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        que.push(num);
    }
    int ans = 0;
    while (que.size() != 1)
    {
        int num = que.top();
        que.pop();
        num += que.top();
        que.pop();
        ans += num;
        que.push(num);
    }
    cout << ans << endl;
    return 0;
}
