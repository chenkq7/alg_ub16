/**
 * example:
 * 2 3
 * 
 * total num of rectangle(include square) is: i.e. sum(1..m) * sum(1..n)
 * sum(1*1 1*2 1*3
 *     2*1 2*2 2*3) = sum(1,2) * sum(1,2,3) = 3*6 = 18
 * 
 * total num of square can be calculated by recursion
 * 
 * calculate squares in rectangle grid can be converted to calculate squares in square grid
*/

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

inline ll sumFrom1To(ll num)
{
    return (1 + num) * num / 2;
}

/**
 * @brief calculate the num of squares in this square grid
 * @param length the side length of the square grid
 * @return how many squares in this square grid
 * 
*/
ll query_square(ll length)
{
    if (length == 1)
        return 1;
    return query_square(length - 1) + 2 * sumFrom1To(length - 1) + length;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    ll ans = sumFrom1To(min(m, n)) * abs(n - m) + query_square(min(m, n));
    cout << ans << " " << sumFrom1To(m) * sumFrom1To(n) - ans;
    return 0;
}
