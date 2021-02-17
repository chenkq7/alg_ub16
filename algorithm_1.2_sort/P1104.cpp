#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

struct student
{
    string name;
    int data[4];
};

bool le(const student &left, const student &right)
{
    for (int i = 0; i < sizeof(left.data) / sizeof(left.data[0]); i++)
    {
        if (left.data[i] != right.data[i])
            return left.data[i] < right.data[i];
    }
    assert(false);
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<student> vec;
    while (n--)
    {
        student tmp;
        cin >> tmp.name >> tmp.data[0] >> tmp.data[1] >> tmp.data[2];
        tmp.data[3] = n;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), ::le);
    for (const auto& item : vec)
        cout << item.name << endl;
    return 0;
}
