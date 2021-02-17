#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

const int NMAX = 5e4 + 5;

struct point
{
    int x, y, z;
} points[NMAX];

bool le(const point &left, const point &right) { return left.z < right.z; }

inline double distance(const point &left, const point &right)
{
    double tmp = pow(left.x - right.x, 2) + pow(left.y - right.y, 2) + pow(left.z - right.z, 2);
    return sqrt(tmp);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y >> points[i].z;
    //
    sort(&points[0], &points[n], ::le);
    double ans = 0;
    for (int i = 1; i < n; i++)
        ans += ::distance(points[i - 1], points[i]);
    //
    cout << setprecision(3) << fixed << ans;
    // auto flag_ = cout.flags(ios::fixed);  // -std=c++14+
    // auto prec_ = cout.precision(3);
    // cout << ans << endl;
    // cout.flags(flag_);
    // cout.precision(prec_);
    return 0;
}
