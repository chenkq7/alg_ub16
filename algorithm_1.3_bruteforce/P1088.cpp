#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    copy_n(istream_iterator<int>(cin), n, back_inserter(vec));
    while (m--)
        next_permutation(vec.begin(), vec.end());
    copy_n(vec.begin(), n, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
