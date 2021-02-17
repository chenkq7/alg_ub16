#include <iostream>
#include <vector>
using namespace std;

void wrong_ans()
{
    vector<int> vec = {1, 2, 3, 4};
    int num = 1 * 2 * 3 * 4;
    auto it_last = vec.begin();
    auto it_now = ++vec.begin();
    while (num--)
    {
        for (auto item : vec)
            cout << item << " ";
        cout << endl;
        iter_swap(it_last, it_now);

        if (++it_now == vec.end())
        {
            it_last = vec.begin();
            it_now = ++vec.begin();
        }
        else
        {
            ++it_last;
        }
    }
}