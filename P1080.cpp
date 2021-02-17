#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
const int NMAX = 1e3 + 5;

struct node
{
    ll left, right, mix;
} data[NMAX];

bool cmp(const node &left, const node &right)
{
    if (left.mix != right.mix)
        return left.mix < right.mix;
    return left.left < right.left;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> data[i].left >> data[i].right;
        data[i].mix = data[i].left * data[i].right;
    }
    sort(data + 1, data + n + 1, cmp);
    ll ans = 0, mixLeft = data[0].left;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, mixLeft / data[i].right);
        mixLeft *= data[i].left;
    }
    cout << ans << endl;
    return 0;
}
