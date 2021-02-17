/**
 * 111 112 113
 * 121 122 123
 * 131 132 133
 * 
 * 211 212 213
 * 221 222 223
 * 231 232 233
 * 
 * 311 312 313
 * 321 322 323
 * 331 332 333
 * 
 * 123 find the most max(latest) num in ascending order (* 存在相邻数相等的情况和123的情况类似。)
 * 132 D3
 * 
 * 213 D2
 * 231 D3
 * 
 * 312 D3
 * 321 D3
 * 
 * 贪心：在序列前后加上-1，每次从头开始扫描，删除第一个准备下降的数 
 * 也可以加速到O(len(num)), 在删除一个数时，他前面的序是不会变的，
 * 所以下次删数时，最多删除该该数前的内个数。所以只需要指针前移一位即可。
 * 1754382 4
 * //754/8
 * */

#include <iostream>
using namespace std;
const int NMAX = 250 + 5;

char c;
int value[NMAX], to[NMAX], n, k;

int main(int argc, char const *argv[])
{
    value[0] = -1, to[0] = 1;
    cin.get(c);
    while (c >= '0' && c <= '9')
    {
        n++, value[n] = c - '0', to[n] = n + 1;
        cin.get(c);
    }
    value[n + 1] = -1, to[n + 1] = -1;

    cin >> k;
    while (k--)
    {
        int prev = 0, ind = to[prev], next = to[ind];
        while (1)
        {
            if (value[ind] > value[next])
                break;
            prev = ind, ind = next, next = to[next];
        }
        to[prev] = next;
    }
    int ind = to[0];
    while (!value[ind])
        ind = to[ind];
    if (to[ind] > 0)
        do
        {
            cout << value[ind];
            ind = to[ind];
        } while (to[ind] > 0);
    else
        cout << 0;
    return 0;
}
